/**
 * Copyright (C) 2015 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/d3d8to9#license
 */

#include "d3d8to9.hpp"

// IDirect3D8
HRESULT STDMETHODCALLTYPE Direct3D8::QueryInterface(REFIID riid, void **ppvObj)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	
	if (ppvObj == nullptr)
	{
		return E_POINTER;
	}

	if (riid == __uuidof(this) ||
		riid == __uuidof(IUnknown))
	{
		AddRef();

		*ppvObj = this;

		return S_OK;
	}

	return _proxy->QueryInterface(riid, ppvObj);
}
ULONG STDMETHODCALLTYPE Direct3D8::AddRef()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->AddRef();
}
ULONG STDMETHODCALLTYPE Direct3D8::Release()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	const auto ref = _proxy->Release();

	if (ref == 0)
	{
		delete this;
	}

	return ref;
}
HRESULT STDMETHODCALLTYPE Direct3D8::RegisterSoftwareDevice(void *pInitializeFunction)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->RegisterSoftwareDevice(pInitializeFunction);
}
UINT STDMETHODCALLTYPE Direct3D8::GetAdapterCount()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetAdapterCount();
}
HRESULT STDMETHODCALLTYPE Direct3D8::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER8 *pIdentifier)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (pIdentifier == nullptr)
	{
		return D3DERR_INVALIDCALL;
	}

	D3DADAPTER_IDENTIFIER9 identifier;

	if ((Flags & D3DENUM_NO_WHQL_LEVEL) == 0)
	{
		Flags |= D3DENUM_WHQL_LEVEL;
	}
	else
	{
		Flags ^= D3DENUM_NO_WHQL_LEVEL;
	}

	const auto hr = _proxy->GetAdapterIdentifier(Adapter, Flags, &identifier);

	if (FAILED(hr))
	{
		return hr;
	}

	convert_adapter_identifier(identifier, *pIdentifier);

	return D3D_OK;
}

static const D3DFORMAT AdapterFormats[] = { D3DFMT_A8R8G8B8, D3DFMT_X8R8G8B8, D3DFMT_R5G6B5, D3DFMT_X1R5G5B5, D3DFMT_A1R5G5B5, D3DFMT_A2R10G10B10 };
UINT STDMETHODCALLTYPE Direct3D8::GetAdapterModeCount(UINT Adapter)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	UINT count = 0;

	for (auto format : AdapterFormats)
	{
		count += _proxy->GetAdapterModeCount(Adapter, format);
	}

	return count;
}
HRESULT STDMETHODCALLTYPE Direct3D8::EnumAdapterModes(UINT Adapter, UINT Mode, D3DDISPLAYMODE *pMode)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (pMode == nullptr)
	{
		return D3DERR_INVALIDCALL;
	}

	UINT offset = 0;

	for (auto format : AdapterFormats)
	{
		const auto modes = _proxy->GetAdapterModeCount(Adapter, format);

		if (modes == 0)
		{
			continue;
		}

		if (Mode < offset + modes)
		{
			return _proxy->EnumAdapterModes(Adapter, format, Mode - offset, pMode);
		}

		offset += modes;
	}

	return D3DERR_INVALIDCALL;
}
HRESULT STDMETHODCALLTYPE Direct3D8::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE *pMode)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetAdapterDisplayMode(Adapter, pMode);
}
HRESULT STDMETHODCALLTYPE Direct3D8::CheckDeviceType(UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->CheckDeviceType(Adapter, CheckType, DisplayFormat, BackBufferFormat, bWindowed);
}
HRESULT STDMETHODCALLTYPE Direct3D8::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
}
HRESULT STDMETHODCALLTYPE Direct3D8::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, nullptr);
}
HRESULT STDMETHODCALLTYPE Direct3D8::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}
HRESULT STDMETHODCALLTYPE Direct3D8::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS8 *pCaps)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (pCaps == nullptr)
	{
		return D3DERR_INVALIDCALL;
	}

	D3DCAPS9 caps;

	const auto hr = _proxy->GetDeviceCaps(Adapter, DeviceType, &caps);

	if (FAILED(hr))
	{
		return hr;
	}

	convert_caps(caps, *pCaps);

	return D3D_OK;
}
HMONITOR STDMETHODCALLTYPE Direct3D8::GetAdapterMonitor(UINT Adapter)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetAdapterMonitor(Adapter);
}
HRESULT STDMETHODCALLTYPE Direct3D8::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS8 *pPresentationParameters, Direct3DDevice8 **ppReturnedDeviceInterface)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

#ifndef D3D8TO9NOLOG
	LOG << "Redirecting '" << "IDirect3D8::CreateDevice" << "(" << this << ", " << Adapter << ", " << DeviceType << ", " << hFocusWindow << ", " << BehaviorFlags << ", " << pPresentationParameters << ", " << ppReturnedDeviceInterface << ")' ..." << std::endl;
#endif

	if (pPresentationParameters == nullptr || ppReturnedDeviceInterface == nullptr)
	{
		return D3DERR_INVALIDCALL;
	}

	*ppReturnedDeviceInterface = nullptr;

	D3DPRESENT_PARAMETERS pp;
	IDirect3DDevice9 *device = nullptr;

	convert_present_parameters(*pPresentationParameters, pp);

	const auto hr = _proxy->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, &pp, &device);

	if (FAILED(hr))
	{
		return hr;
	}

	const auto device_proxy = new Direct3DDevice8(this, device, (pp.Flags & D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL) != 0);

	// Set default render target
	IDirect3DSurface9 *rendertarget = nullptr, *depthstencil = nullptr;
	Direct3DSurface8 *rendertarget_proxy = nullptr, *depthstencil_proxy = nullptr;

	device->GetRenderTarget(0, &rendertarget);
	device->GetDepthStencilSurface(&depthstencil);

	if (rendertarget != nullptr)
	{
		rendertarget_proxy = new Direct3DSurface8(device_proxy, rendertarget);
	}
	if (depthstencil != nullptr)
	{
		depthstencil_proxy = new Direct3DSurface8(device_proxy, depthstencil);
	}

	device_proxy->SetRenderTarget(rendertarget_proxy, depthstencil_proxy);

	if (rendertarget_proxy != nullptr)
	{
		rendertarget_proxy->Release();
	}
	if (depthstencil_proxy != nullptr)
	{
		depthstencil_proxy->Release();
	}

	*ppReturnedDeviceInterface = device_proxy;

	return D3D_OK;
}
