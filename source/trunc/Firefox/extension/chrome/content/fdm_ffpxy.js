var freeDldMgr_FfPrefs = Components.classes["@mozilla.org/preferences;1"].getService (Components.interfaces.nsIPrefBranch);
if (!freeDldMgr_FfPrefs.addObserver)
	freeDldMgr_FfPrefs = Components.classes["@mozilla.org/preferences;1"].getService (Components.interfaces.nsIPrefBranch2);


// write current proxy settings of browser to registry settings of FDM
// prot - name of protocol ("http", "ssl", "ftp")
function freeDldMgr_ReadProxyPrefs_protocol (prot)
{
  var str = "network.proxy."; 
  str += prot;
  freeDldMgr_FDM.SetProxy (prot, freeDldMgr_FfPrefs.getCharPref (str), freeDldMgr_FfPrefs.getIntPref (str + "_port"));
}

function freeDldMgr_ReadProxyPrefs ()
{
  freeDldMgr_FDM.SetProxyType (freeDldMgr_FfPrefs.getIntPref ("network.proxy.type"));
  freeDldMgr_ReadProxyPrefs_protocol ("http");
  freeDldMgr_ReadProxyPrefs_protocol ("ssl");
  freeDldMgr_ReadProxyPrefs_protocol ("ftp");
}

/*============== Listen prefs =================*/

var freeDldMgr_prefsListener = { 
 observe: function (subject, topic, data) {
        // settings was changed. update proxy settings.
        freeDldMgr_ReadProxyPrefs ();
 },

 QueryInterface: function (aIID) {
   if (!aIID.equals (Components.interfaces.nsISupports) && !aIID.equals (Components.interfaces.nsIObserver))
      throw Components.result.NS_ERROR_NO_INTERFACE; 
   return this;
 }
};

freeDldMgr_ReadProxyPrefs ();

if (freeDldMgr_FfPrefs.addObserver) {
	freeDldMgr_FfPrefs.addObserver ("network.proxy", freeDldMgr_prefsListener, false);
	window.addEventListener("unload",  freeDldMgr_ffpxy_unload, false);
}

function freeDldMgr_ffpxy_unload ()
{
	if (freeDldMgr_FfPrefs.removeObserver)
		freeDldMgr_FfPrefs.removeObserver ("network.proxy", freeDldMgr_prefsListener, false);
	window.removeEventListener("unload",  freeDldMgr_ffpxy_unload);
}