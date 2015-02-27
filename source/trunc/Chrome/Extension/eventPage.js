
// Array Remove - By John Resig (MIT Licensed)
Array.prototype.remove = function(from, to) {
  var rest = this.slice((to || from) + 1 || this.length);
  this.length = from < 0 ? this.length + from : from;
  return this.push.apply(this, rest);
};

var port = chrome.runtime.connectNative('com.vms.fdm');
var suggest_callbacks = [];
var _config = { "monitor": false };
var dialog_shown = false;

function UrlToFdm(id, url, referrer, page, postdata)
{
	if(dialog_shown)
		return;
	chrome.cookies.getAll({ 'url': url },
		function(c) {
			cookie_string = c.map(function(cookie){
				return cookie.name+"="+cookie.value+";"; }).join(' ');
			var origUrl = url;
			if(redirects.hasOwnProperty(url))
			{
				var newUrl = redirects[url];
				delete redirects[url];
				url = newUrl;
			}
			port.postMessage({
				'id': id,
				'list': false,
				'page': ((typeof page !== 'undefined') ? page : false),
				'url': url,
				'origUrl': origUrl,
				'cookies': cookie_string,
				'referrer': referrer,
				'post': ((typeof postdata !== 'undefined') ? postdata : ""),
				'useragent': navigator.userAgent
			});
			dialog_shown = true;
		}
	);
}

function UrlListToFdm(urllist, referrer)
{
	chrome.cookies.getAll({ 'url': referrer },
		function(c) {
			cookie_string = c.map(function(cookie){
				return cookie.name+"="+cookie.value+";" }).join(' ');
			port.postMessage({
				'id': -1,
				'list': true,
				'url': urllist,
				'cookies': cookie_string,
				'referrer': referrer,
				'post': "",
				'useragent': navigator.userAgent
			});
		}
	);
}

function CreateContextMenu()
{
	if(!_config.monitor)
		return;

	if(_config.menu._this)
		chrome.contextMenus.create({
			"id": "this",
			"title": chrome.i18n.getMessage("menuThis"),
			"contexts": [ "image", "link" ],
			"onclick" :
				function(e) {
					if(e.linkUrl)
						UrlToFdm(-1, e.linkUrl, e.pageUrl);
					else if(e.mediaType === "image")
						UrlToFdm(-1, encodeURI(e.srcUrl), e.pageUrl);
				}
		});
	if(_config.menu.all)
		chrome.contextMenus.create({
			"id": "all",
			"title": chrome.i18n.getMessage("menuAll"),
			"contexts": [ "page" ]
		});

	if(_config.menu.selected)
		chrome.contextMenus.create({
			"id": "selected",
			"title": chrome.i18n.getMessage("menuSelected"),
			"contexts": [ "selection" ]
		});

	if(_config.menu.page)
		chrome.contextMenus.create({
			"id": "page",
			"title": chrome.i18n.getMessage("menuSite"),
			"contexts": [ "page" ]
		});

	chrome.contextMenus.onClicked.addListener(
		function(info, tab) {
			switch(info.menuItemId)
			{
				case "all":
					chrome.tabs.executeScript(
						tab.id, 
						{ "code":
							"JSON.stringify([].map.call(document.getElementsByTagName('a'), function(n) {return n.href;}).concat([].map.call(document.getElementsByTagName('img'), function(n) {return n.src;})));"
						},
						function(h) {
							UrlListToFdm(eval(h[0]).join('\n'), tab.url);
						}
					);
					break;

				case "selected":
					chrome.tabs.executeScript(
						tab.id, 
						{ "code":
							"var s=document.getSelection(); var dv=document.createElement('div'); dv.appendChild(s.getRangeAt(0).cloneContents());JSON.stringify([].map.call(dv.getElementsByTagName('a'), function(n) {return n.href;}))"
						},
						function(h) {
							UrlListToFdm(eval(h[0]).join('\n'), tab.url);
						}
					);
					break;

				case "page":
					UrlToFdm(-1, tab.url, tab.url, true);
					break;

				default:
					break;
			}
		}
	);
}

port.onMessage.addListener(
	function(message) {
		dialog_shown = false;
		switch(message.id)
		{
			case -2:  // initialization
				_config = message.result;
				CreateContextMenu();
				break;

			case -1:  // menu
				break;

			default:  // ordinary download
				if(message.result)
					chrome.downloads.cancel(message.id);
				else
					if(_config.allow_download)
						chrome.downloads.resume(message.id);
					else
						chrome.downloads.cancel(message.id);
				suggest_callbacks[message.id]();
				suggest_callbacks.remove(message.id);
				break;
		}
	}
);

function OpenFDMHomepage()
{
	chrome.windows.create({
		'url': 'chrome-extension://ahmpjcflkgiildlgicmcieglgoilbfdp/install.html',
		'type': 'popup',
		'width': 620,
		'height': 500
	});
}

port.onDisconnect.addListener(
	function() {
		chrome.runtime.getPlatformInfo(function(info) {
			if(info.os == "win")
			{
				if(chrome.runtime.lastError)
				{
					message = chrome.runtime.lastError.message;
					console.log(message);
					if(message.indexOf("Access") != -1)
					{
						// ext id changed??
						OpenFDMHomepage();
						console.log(chrome.i18n.getMessage("installCorrupted"));
					}
					else if(message.indexOf("not found") != -1)
					{
						// user have just extension, not FDM itself
						OpenFDMHomepage();
						console.log(chrome.i18n.getMessage("installMissing"));
					}
					// TODO : "Native host has exited." -> restart or something
				} else
				{
					OpenFDMHomepage();
					console.log(chrome.i18n.getMessage("installUnknownError"));
				}
			}
		});
	}
);

chrome.downloads.onDeterminingFilename.addListener(
	function(downloadItem, suggest) {
		if(!_config.monitor)
		{
			suggest();
			return;
		}

		var size = downloadItem.totalBytes;
		if(size != -1 && size < _config.skip_smaller)
		{
			suggest();
			return;
		}
		
		if(dialog_shown)
		{
			suggest();
			return;
		}

		// workaround for MEGA.co.nz
		if(downloadItem.url.toLowerCase().indexOf("filesystem:") == 0)
		{
			suggest();
			return;
		}

		// Chrome starts download anyways, but
		// it is hidden until call of suggest() callback.
		chrome.downloads.pause(downloadItem.id);
		UrlToFdm(downloadItem.id, downloadItem.url, downloadItem.referrer);
		suggest_callbacks[downloadItem.id] = suggest;
		return true;
	}
);


// special processing for redirects & POST requests returning files (like rutracker.org)
//

var redirects = [];
var request_bodies  = [];
var request_headers = [];

chrome.webRequest.onBeforeRequest.addListener(
	function(details) {
		if(details.method == "POST")
		{
			request_bodies[details.requestId] = "&";
			if(undefined != details.requestBody && undefined != details.requestBody.formData)
			{
				for(var field in details.requestBody.formData)
				{
					for(var i = 0; i < details.requestBody.formData[field].length; ++i)
						request_bodies[details.requestId] +=
							(field +
							"=" +
							encodeURIComponent(details.requestBody.formData[field][i]) +
							"&");
				}
			}
			// FDM sends only application/x-www-form-urlencoded anyways, so
			//  no need to process details.requestBody.raw here.
		}
	},
	{urls: ["<all_urls>"]},
	["requestBody"]
);

chrome.webRequest.onSendHeaders.addListener(
	function(details) {
		if(details.method == "POST")
			request_headers[details.requestId] = details.requestHeaders;
	},
	{urls: ["<all_urls>"]},
	["requestHeaders"]
);

chrome.webRequest.onHeadersReceived.addListener(
	function(details) {
		if((details.statusLine.indexOf("301") != -1 || details.statusLine.indexOf("302") != -1))
		{
			var newUrl = "";
			for(var i = 0; i < details.responseHeaders.length; ++i)
			{
				if(details.responseHeaders[i].name.toLowerCase()=="location")
				{
					newUrl = details.responseHeaders[i].value;
					break;
				}
			}
			if(newUrl != "")
				redirects[details.url] = newUrl;
		}
		if(details.method == "POST")
		{
			var result;
			var file = false;
			if(details.type != "xmlhttprequest")
				for(var i = 0; i < details.responseHeaders.length; ++i)
				{
					if(details.responseHeaders[i].name.toLowerCase()=="content-disposition")
						file = true;
					// prevent AJAX from breaking
					if(details.responseHeaders[i].name.toLowerCase()=="content-type" &&
						(details.responseHeaders[i].value.toLowerCase().indexOf("json") != -1 ||
						details.responseHeaders[i].value.toLowerCase().indexOf("text") != -1 ||
						details.responseHeaders[i].value.toLowerCase().indexOf("javascript") != -1))
					{
						file = false;
						break;
					}
				}
			if(file && _config.monitor)
			{
				var referrer = "";
				for(var j = 0; j < request_headers[details.requestId].length; ++j)
				{
					var rheader = request_headers[details.requestId][j];
					if(rheader.name.toLowerCase()=="referrer" ||
							rheader.name.toLowerCase()=="referer")
						referrer = rheader.value;
				}
				UrlToFdm(-1, details.url, referrer, false,
					request_bodies[details.requestId]);
				chrome.tabs.update( { 'url': referrer });
				result = { 'cancel': true };
			}
			request_bodies.remove(details.requestId);
			request_headers.remove(details.requestId);
			return result;
		}
	},
	{urls: ["<all_urls>"]},
	["blocking", "responseHeaders"]
);
