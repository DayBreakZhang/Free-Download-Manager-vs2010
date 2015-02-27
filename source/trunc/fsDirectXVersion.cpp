/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsDirectXVersion.h"
#include <basetsd.h>
#include <ddraw.h>
#include <dinput.h>
#include <dmusici.h>

typedef HRESULT(WINAPI * DIRECTDRAWCREATE)( GUID*, LPDIRECTDRAW*, IUnknown* );
typedef HRESULT(WINAPI * DIRECTDRAWCREATEEX)( GUID*, VOID**, REFIID, IUnknown* );
typedef HRESULT(WINAPI * DIRECTINPUTCREATE)( HINSTANCE, DWORD, LPDIRECTINPUT*,
                                             IUnknown* );

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsDirectXVersion::fsDirectXVersion()
{

}

fsDirectXVersion::~fsDirectXVersion()
{

}

DWORD fsDirectXVersion::GetCurrentVersion()
{
	DIRECTDRAWCREATE     DirectDrawCreate   = NULL;
    DIRECTDRAWCREATEEX   DirectDrawCreateEx = NULL;
    DIRECTINPUTCREATE    DirectInputCreate  = NULL;
    HINSTANCE            hDDrawDLL          = NULL;
    HINSTANCE            hDInputDLL         = NULL;
    HINSTANCE            hD3D8DLL           = NULL;
    LPDIRECTDRAW         pDDraw             = NULL;
    LPDIRECTDRAW2        pDDraw2            = NULL;
    LPDIRECTDRAWSURFACE  pSurf              = NULL;
    LPDIRECTDRAWSURFACE3 pSurf3             = NULL;
    LPDIRECTDRAWSURFACE4 pSurf4             = NULL;
    DWORD                dwDXVersion        = 0;
    HRESULT              hr;

    
    hDDrawDLL = LoadLibrary( "DDRAW.DLL" );
    if( hDDrawDLL == NULL )
    {
        dwDXVersion = 0;
        return dwDXVersion;
    }

    
    DirectDrawCreate = (DIRECTDRAWCREATE)GetProcAddress( hDDrawDLL, "DirectDrawCreate" );
    if( DirectDrawCreate == NULL )
    {
        dwDXVersion = 0;
        FreeLibrary( hDDrawDLL );
        return dwDXVersion;
    }

    hr = DirectDrawCreate( NULL, &pDDraw, NULL );
    if( FAILED(hr) )
    {
        dwDXVersion = 0;
        FreeLibrary( hDDrawDLL );
        return dwDXVersion;
    }

    
    dwDXVersion = 0x100;

    
    hr = pDDraw->QueryInterface( IID_IDirectDraw2, (VOID**)&pDDraw2 );
    if( FAILED(hr) )
    {
        
        pDDraw->Release();
        FreeLibrary( hDDrawDLL );
        return dwDXVersion;
    }

    
    pDDraw2->Release();
    dwDXVersion = 0x200;

	
    
	

    
    hDInputDLL = LoadLibrary( "DINPUT.DLL" );
    if( hDInputDLL == NULL )
    {
        
        pDDraw->Release();
        return dwDXVersion;
    }

    DirectInputCreate = (DIRECTINPUTCREATE)GetProcAddress( hDInputDLL,
                                                        "DirectInputCreateA" );
    if( DirectInputCreate == NULL )
    {
        
        FreeLibrary( hDInputDLL );
        FreeLibrary( hDDrawDLL );
        pDDraw->Release();
        return dwDXVersion;
    }

    
    dwDXVersion = 0x300;
    FreeLibrary( hDInputDLL );

    

	
    
	

    
    
    DDSURFACEDESC ddsd;
    ZeroMemory( &ddsd, sizeof(ddsd) );
    ddsd.dwSize         = sizeof(ddsd);
    ddsd.dwFlags        = DDSD_CAPS;
    ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

    hr = pDDraw->SetCooperativeLevel( NULL, DDSCL_NORMAL );
    if( FAILED(hr) )
    {
        
        pDDraw->Release();
        FreeLibrary( hDDrawDLL );
        dwDXVersion = 0;
        return dwDXVersion;
    }

    hr = pDDraw->CreateSurface( &ddsd, &pSurf, NULL );
    if( FAILED(hr) )
    {
        
        pDDraw->Release();
        FreeLibrary( hDDrawDLL );
        dwDXVersion = 0;
        return dwDXVersion;
    }

    
    if( FAILED( pSurf->QueryInterface( IID_IDirectDrawSurface3,
                                       (VOID**)&pSurf3 ) ) )
    {
        pDDraw->Release();
        FreeLibrary( hDDrawDLL );
        return dwDXVersion;
    }

    
    dwDXVersion = 0x500;

	
    
	

    
    if( FAILED( pSurf->QueryInterface( IID_IDirectDrawSurface4,
                                       (VOID**)&pSurf4 ) ) )
    {
        pDDraw->Release();
        FreeLibrary( hDDrawDLL );
        return dwDXVersion;
    }

    
    dwDXVersion = 0x600;
    pSurf->Release();
    pDDraw->Release();

	
    
	

    
    LPDIRECTMUSIC pDMusic = NULL;
    CoInitialize( NULL );
    hr = CoCreateInstance( CLSID_DirectMusic, NULL, CLSCTX_INPROC_SERVER,
                           IID_IDirectMusic, (VOID**)&pDMusic );
    if( FAILED(hr) )
    {
        FreeLibrary( hDDrawDLL );
        return dwDXVersion;
    }

    
    dwDXVersion = 0x601;
    pDMusic->Release();
    CoUninitialize();
    

	
    
	

    
    LPDIRECTDRAW7 pDD7;
    DirectDrawCreateEx = (DIRECTDRAWCREATEEX)GetProcAddress( hDDrawDLL,
                                                       "DirectDrawCreateEx" );
    if( NULL == DirectDrawCreateEx )
    {
        FreeLibrary( hDDrawDLL );
        return dwDXVersion;
    }

    if( FAILED( DirectDrawCreateEx( NULL, (VOID**)&pDD7, IID_IDirectDraw7,
                                    NULL ) ) )
    {
        FreeLibrary( hDDrawDLL );
        return dwDXVersion;
    }

    
    dwDXVersion = 0x700;
    pDD7->Release();

	
    
	

    
    hD3D8DLL = LoadLibrary( "D3D8.DLL" );
    if( hD3D8DLL == NULL )
    {
	    FreeLibrary( hDDrawDLL );
        return dwDXVersion;
    }

    
    dwDXVersion = 0x800;

	
    
	

    
    FreeLibrary( hDDrawDLL );
    FreeLibrary( hD3D8DLL );
    
    return dwDXVersion;
}
