
var clicked = false;

function click_hander() {
	clicked = true;
	chrome.tabs.create({
		'url': 'http://files2.freedownloadmanager.org/fdminst.exe'
	});
	window.close();
	return false;
};

window.onload = function() {
	document.getElementById("install_button").addEventListener("click", click_hander);
};

window.onbeforeunload = function() {
	if(!clicked)
		chrome.management.uninstallSelf();
	return null;
};
