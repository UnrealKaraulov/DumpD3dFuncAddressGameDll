/**
 * Copyright (C) 2015 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/d3d8to9#license
 */

#include "d3d8to9.hpp"

// IDirect3DVolume8
HRESULT STDMETHODCALLTYPE Direct3DVolume8::QueryInterface(REFIID riid, void **ppvObj)
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
ULONG STDMETHODCALLTYPE Direct3DVolume8::AddRef()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	InterlockedIncrement(&_ref);

	return _proxy->AddRef();
}
ULONG STDMETHODCALLTYPE Direct3DVolume8::Release()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	const auto ref = _proxy->Release();
	ULONG myRef = InterlockedDecrement(&_ref);

	if (myRef == 0)
	{
		delete this;
	}

	return ref;
}
HRESULT STDMETHODCALLTYPE Direct3DVolume8::GetDevice(Direct3DDevice8 **ppDevice)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (ppDevice == nullptr)
	{
		return D3DERR_INVALIDCALL;
	}

	_device->AddRef();

	*ppDevice = _device;

	return D3D_OK;
}
HRESULT STDMETHODCALLTYPE Direct3DVolume8::SetPrivateData(REFGUID refguid, CONST void *pData, DWORD SizeOfData, DWORD Flags)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->SetPrivateData(refguid, pData, SizeOfData, Flags);
}
HRESULT STDMETHODCALLTYPE Direct3DVolume8::GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetPrivateData(refguid, pData, pSizeOfData);
}
HRESULT STDMETHODCALLTYPE Direct3DVolume8::FreePrivateData(REFGUID refguid)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->FreePrivateData(refguid);
}
HRESULT STDMETHODCALLTYPE Direct3DVolume8::GetContainer(REFIID riid, void **ppContainer)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetContainer(riid, ppContainer);
}
HRESULT STDMETHODCALLTYPE Direct3DVolume8::GetDesc(D3DVOLUME_DESC8 *pDesc)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (pDesc == nullptr)
	{
		return D3DERR_INVALIDCALL;
	}

	D3DVOLUME_DESC desc;

	const auto hr = _proxy->GetDesc(&desc);

	if (FAILED(hr))
	{
		return hr;
	}

	convert_volume_desc(desc, *pDesc);

	return D3D_OK;
}
HRESULT STDMETHODCALLTYPE Direct3DVolume8::LockBox(D3DLOCKED_BOX *pLockedVolume, CONST D3DBOX *pBox, DWORD Flags)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->LockBox(pLockedVolume, pBox, Flags);
}
HRESULT STDMETHODCALLTYPE Direct3DVolume8::UnlockBox()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->UnlockBox();
}
