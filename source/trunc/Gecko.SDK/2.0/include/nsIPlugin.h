/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/modules/plugin/base/public/nsIPlugin.idl
 */

#ifndef __gen_nsIPlugin_h__
#define __gen_nsIPlugin_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "npapi.h"
#define MOZ_PLUGIN_CONTRACTID \
  "@mozilla.org/plugin/plugin;1"
class nsIPluginInstance; /* forward declaration */


/* starting interface:    nsIPlugin */
#define NS_IPLUGIN_IID_STR "94c32fea-5c50-49d3-9d3d-9047cd342777"

#define NS_IPLUGIN_IID \
  {0x94c32fea, 0x5c50, 0x49d3, \
    { 0x9d, 0x3d, 0x90, 0x47, 0xcd, 0x34, 0x27, 0x77 }}

class NS_NO_VTABLE nsIPlugin : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGIN_IID)

  /**
   * Creates a new plugin instance, based on a MIME type. This
   * allows different impelementations to be created depending on
   * the specified MIME type.
   */
  /* void createPluginInstance (out nsIPluginInstance aResult); */
  NS_IMETHOD CreatePluginInstance(nsIPluginInstance **aResult NS_OUTPARAM) = 0;

  /**
   * Called when the browser is done with the plugin factory, or when
   * the plugin is disabled by the user.
   *
   * (Corresponds to NPP_Shutdown.)
   *
   * @result - NS_OK if this operation was successful
   */
  /* void shutdown (); */
  NS_IMETHOD Shutdown(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPlugin, NS_IPLUGIN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGIN \
  NS_IMETHOD CreatePluginInstance(nsIPluginInstance **aResult NS_OUTPARAM); \
  NS_IMETHOD Shutdown(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGIN(_to) \
  NS_IMETHOD CreatePluginInstance(nsIPluginInstance **aResult NS_OUTPARAM) { return _to CreatePluginInstance(aResult); } \
  NS_IMETHOD Shutdown(void) { return _to Shutdown(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGIN(_to) \
  NS_IMETHOD CreatePluginInstance(nsIPluginInstance **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreatePluginInstance(aResult); } \
  NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPlugin : public nsIPlugin
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGIN

  nsPlugin();

private:
  ~nsPlugin();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPlugin, nsIPlugin)

nsPlugin::nsPlugin()
{
  /* member initializers and constructor code */
}

nsPlugin::~nsPlugin()
{
  /* destructor code */
}

/* void createPluginInstance (out nsIPluginInstance aResult); */
NS_IMETHODIMP nsPlugin::CreatePluginInstance(nsIPluginInstance **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void shutdown (); */
NS_IMETHODIMP nsPlugin::Shutdown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPlugin_h__ */
