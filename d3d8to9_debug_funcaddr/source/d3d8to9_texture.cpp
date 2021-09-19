/**
 * Copyright (C) 2015 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/d3d8to9#license
 */

#include "d3d8to9.hpp"

// IDirect3DTexture8
HRESULT STDMETHODCALLTYPE Direct3DTexture8::QueryInterface(REFIID riid, void **ppvObj)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (ppvObj == nullptr)
	{
		return E_POINTER;
	}

	if (riid == __uuidof(this) ||
		riid == __uuidof(IUnknown) ||
		riid == __uuidof(Direct3DResource8) ||
		riid == __uuidof(Direct3DBaseTexture8))
	{
		AddRef();

		*ppvObj = this;

		return S_OK;
	}

	return _proxy->QueryInterface(riid, ppvObj);
}
ULONG STDMETHODCALLTYPE Direct3DTexture8::AddRef()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	InterlockedIncrement(&_ref);

	return _proxy->AddRef();
}
ULONG STDMETHODCALLTYPE Direct3DTexture8::Release()
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
HRESULT STDMETHODCALLTYPE Direct3DTexture8::GetDevice(Direct3DDevice8 **ppDevice)
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
HRESULT STDMETHODCALLTYPE Direct3DTexture8::SetPrivateData(REFGUID refguid, CONST void *pData, DWORD SizeOfData, DWORD Flags)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->SetPrivateData(refguid, pData, SizeOfData, Flags);
}
HRESULT STDMETHODCALLTYPE Direct3DTexture8::GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetPrivateData(refguid, pData, pSizeOfData);
}
HRESULT STDMETHODCALLTYPE Direct3DTexture8::FreePrivateData(REFGUID refguid)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->FreePrivateData(refguid);
}
DWORD STDMETHODCALLTYPE Direct3DTexture8::SetPriority(DWORD PriorityNew)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->SetPriority(PriorityNew);
}
DWORD STDMETHODCALLTYPE Direct3DTexture8::GetPriority()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetPriority();
}
void STDMETHODCALLTYPE Direct3DTexture8::PreLoad()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	_proxy->PreLoad();
}
D3DRESOURCETYPE STDMETHODCALLTYPE Direct3DTexture8::GetType()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return D3DRTYPE_TEXTURE;
}
DWORD STDMETHODCALLTYPE Direct3DTexture8::SetLOD(DWORD LODNew)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->SetLOD(LODNew);
}
DWORD STDMETHODCALLTYPE Direct3DTexture8::GetLOD()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetLOD();
}
DWORD STDMETHODCALLTYPE Direct3DTexture8::GetLevelCount()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetLevelCount();
}
HRESULT STDMETHODCALLTYPE Direct3DTexture8::GetLevelDesc(UINT Level, D3DSURFACE_DESC8 *pDesc)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (pDesc == nullptr)
	{
		return D3DERR_INVALIDCALL;
	}

	D3DSURFACE_DESC desc;

	const auto hr = _proxy->GetLevelDesc(Level, &desc);

	if (FAILED(hr))
	{
		return hr;
	}

	convert_surface_desc(desc, *pDesc);

	return D3D_OK;
}
HRESULT STDMETHODCALLTYPE Direct3DTexture8::GetSurfaceLevel(UINT Level, Direct3DSurface8 **ppSurfaceLevel)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (ppSurfaceLevel == nullptr)
	{
		return D3DERR_INVALIDCALL;
	}

	*ppSurfaceLevel = nullptr;

	IDirect3DSurface9 *surface = nullptr;

	const auto hr = _proxy->GetSurfaceLevel(Level, &surface);

	if (FAILED(hr))
	{
		return hr;
	}

	*ppSurfaceLevel = new Direct3DSurface8(_device, surface);

	return D3D_OK;
}
HRESULT STDMETHODCALLTYPE Direct3DTexture8::LockRect(UINT Level, D3DLOCKED_RECT *pLockedRect, CONST RECT *pRect, DWORD Flags)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->LockRect(Level, pLockedRect, pRect, Flags);
}
HRESULT STDMETHODCALLTYPE Direct3DTexture8::UnlockRect(UINT Level)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->UnlockRect(Level);
}
HRESULT STDMETHODCALLTYPE Direct3DTexture8::AddDirtyRect(CONST RECT *pDirtyRect)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->AddDirtyRect(pDirtyRect);
}

// IDirect3DCubeTexture8
HRESULT STDMETHODCALLTYPE Direct3DCubeTexture8::QueryInterface(REFIID riid, void **ppvObj)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (ppvObj == nullptr)
	{
		return E_POINTER;
	}

	if (riid == __uuidof(this) ||
		riid == __uuidof(IUnknown) ||
		riid == __uuidof(Direct3DResource8) ||
		riid == __uuidof(Direct3DBaseTexture8))
	{
		AddRef();

		*ppvObj = this;

		return S_OK;
	}

	return _proxy->QueryInterface(riid, ppvObj);
}
ULONG STDMETHODCALLTYPE Direct3DCubeTexture8::AddRef()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	InterlockedIncrement(&_ref);

	return _proxy->AddRef();
}
ULONG STDMETHODCALLTYPE Direct3DCubeTexture8::Release()
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
HRESULT STDMETHODCALLTYPE Direct3DCubeTexture8::GetDevice(Direct3DDevice8 **ppDevice)
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
HRESULT STDMETHODCALLTYPE Direct3DCubeTexture8::SetPrivateData(REFGUID refguid, CONST void *pData, DWORD SizeOfData, DWORD Flags)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->SetPrivateData(refguid, pData, SizeOfData, Flags);
}
HRESULT STDMETHODCALLTYPE Direct3DCubeTexture8::GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetPrivateData(refguid, pData, pSizeOfData);
}
HRESULT STDMETHODCALLTYPE Direct3DCubeTexture8::FreePrivateData(REFGUID refguid)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->FreePrivateData(refguid);
}
DWORD STDMETHODCALLTYPE Direct3DCubeTexture8::SetPriority(DWORD PriorityNew)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->SetPriority(PriorityNew);
}
DWORD STDMETHODCALLTYPE Direct3DCubeTexture8::GetPriority()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetPriority();
}
void STDMETHODCALLTYPE Direct3DCubeTexture8::PreLoad()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	_proxy->PreLoad();
}
D3DRESOURCETYPE STDMETHODCALLTYPE Direct3DCubeTexture8::GetType()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return D3DRTYPE_CUBETEXTURE;
}
DWORD STDMETHODCALLTYPE Direct3DCubeTexture8::SetLOD(DWORD LODNew)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->SetLOD(LODNew);
}
DWORD STDMETHODCALLTYPE Direct3DCubeTexture8::GetLOD()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetLOD();
}
DWORD STDMETHODCALLTYPE Direct3DCubeTexture8::GetLevelCount()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetLevelCount();
}
HRESULT STDMETHODCALLTYPE Direct3DCubeTexture8::GetLevelDesc(UINT Level, D3DSURFACE_DESC8 *pDesc)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (pDesc == nullptr)
	{
		return D3DERR_INVALIDCALL;
	}

	D3DSURFACE_DESC desc;

	const auto hr = _proxy->GetLevelDesc(Level, &desc);

	if (FAILED(hr))
	{
		return hr;
	}

	convert_surface_desc(desc, *pDesc);

	return D3D_OK;
}
HRESULT STDMETHODCALLTYPE Direct3DCubeTexture8::GetCubeMapSurface(D3DCUBEMAP_FACES FaceType, UINT Level, Direct3DSurface8 **ppCubeMapSurface)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (ppCubeMapSurface == nullptr)
	{
		return D3DERR_INVALIDCALL;
	}

	*ppCubeMapSurface = nullptr;

	IDirect3DSurface9 *surface = nullptr;

	const auto hr = _proxy->GetCubeMapSurface(FaceType, Level, &surface);

	if (FAILED(hr))
	{
		return hr;
	}

	*ppCubeMapSurface = new Direct3DSurface8(_device, surface);;

	return D3D_OK;
}
HRESULT STDMETHODCALLTYPE Direct3DCubeTexture8::LockRect(D3DCUBEMAP_FACES FaceType, UINT Level, D3DLOCKED_RECT *pLockedRect, CONST RECT *pRect, DWORD Flags)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->LockRect(FaceType, Level, pLockedRect, pRect, Flags);
}
HRESULT STDMETHODCALLTYPE Direct3DCubeTexture8::UnlockRect(D3DCUBEMAP_FACES FaceType, UINT Level)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->UnlockRect(FaceType, Level);
}
HRESULT STDMETHODCALLTYPE Direct3DCubeTexture8::AddDirtyRect(D3DCUBEMAP_FACES FaceType, CONST RECT *pDirtyRect)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->AddDirtyRect(FaceType, pDirtyRect);
}

// IDirect3DVolumeTexture8
HRESULT STDMETHODCALLTYPE Direct3DVolumeTexture8::QueryInterface(REFIID riid, void **ppvObj)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (ppvObj == nullptr)
	{
		return E_POINTER;
	}

	if (riid == __uuidof(this) ||
		riid == __uuidof(IUnknown) ||
		riid == __uuidof(Direct3DResource8) ||
		riid == __uuidof(Direct3DBaseTexture8))
	{
		AddRef();

		*ppvObj = this;

		return S_OK;
	}

	return _proxy->QueryInterface(riid, ppvObj);
}
ULONG STDMETHODCALLTYPE Direct3DVolumeTexture8::AddRef()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	InterlockedIncrement(&_ref);

	return _proxy->AddRef();
}
ULONG STDMETHODCALLTYPE Direct3DVolumeTexture8::Release()
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
HRESULT STDMETHODCALLTYPE Direct3DVolumeTexture8::GetDevice(Direct3DDevice8 **ppDevice)
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
HRESULT STDMETHODCALLTYPE Direct3DVolumeTexture8::SetPrivateData(REFGUID refguid, CONST void *pData, DWORD SizeOfData, DWORD Flags)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->SetPrivateData(refguid, pData, SizeOfData, Flags);
}
HRESULT STDMETHODCALLTYPE Direct3DVolumeTexture8::GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetPrivateData(refguid, pData, pSizeOfData);
}
HRESULT STDMETHODCALLTYPE Direct3DVolumeTexture8::FreePrivateData(REFGUID refguid)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->FreePrivateData(refguid);
}
DWORD STDMETHODCALLTYPE Direct3DVolumeTexture8::SetPriority(DWORD PriorityNew)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->SetPriority(PriorityNew);
}
DWORD STDMETHODCALLTYPE Direct3DVolumeTexture8::GetPriority()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetPriority();
}
void STDMETHODCALLTYPE Direct3DVolumeTexture8::PreLoad()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	_proxy->PreLoad();
}
D3DRESOURCETYPE STDMETHODCALLTYPE Direct3DVolumeTexture8::GetType()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return D3DRTYPE_VOLUMETEXTURE;
}
DWORD STDMETHODCALLTYPE Direct3DVolumeTexture8::SetLOD(DWORD LODNew)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->SetLOD(LODNew);
}
DWORD STDMETHODCALLTYPE Direct3DVolumeTexture8::GetLOD()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetLOD();
}
DWORD STDMETHODCALLTYPE Direct3DVolumeTexture8::GetLevelCount()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetLevelCount();
}
HRESULT STDMETHODCALLTYPE Direct3DVolumeTexture8::GetLevelDesc(UINT Level, D3DVOLUME_DESC8 *pDesc)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (pDesc == nullptr)
	{
		return D3DERR_INVALIDCALL;
	}

	D3DVOLUME_DESC desc;

	const auto hr = _proxy->GetLevelDesc(Level, &desc);

	if (FAILED(hr))
	{
		return hr;
	}

	convert_volume_desc(desc, *pDesc);

	return D3D_OK;
}
HRESULT STDMETHODCALLTYPE Direct3DVolumeTexture8::GetVolumeLevel(UINT Level, Direct3DVolume8 **ppVolumeLevel)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (ppVolumeLevel == nullptr)
	{
		return D3DERR_INVALIDCALL;
	}

	*ppVolumeLevel = nullptr;

	IDirect3DVolume9 *volume = nullptr;

	const auto hr = _proxy->GetVolumeLevel(Level, &volume);

	if (FAILED(hr))
	{
		return hr;
	}

	*ppVolumeLevel = new Direct3DVolume8(_device, volume);

	return D3D_OK;
}
HRESULT STDMETHODCALLTYPE Direct3DVolumeTexture8::LockBox(UINT Level, D3DLOCKED_BOX *pLockedVolume, CONST D3DBOX *pBox, DWORD Flags)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->LockBox(Level, pLockedVolume, pBox, Flags);
}
HRESULT STDMETHODCALLTYPE Direct3DVolumeTexture8::UnlockBox(UINT Level)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->UnlockBox(Level);
}
HRESULT STDMETHODCALLTYPE Direct3DVolumeTexture8::AddDirtyBox(CONST D3DBOX *pDirtyBox)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->AddDirtyBox(pDirtyBox);
}
