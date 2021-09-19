/**
 * Copyright (C) 2015 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/d3d8to9#license
 */

#include "d3d8to9.hpp"

// IDirect3DVertexBuffer8
HRESULT STDMETHODCALLTYPE Direct3DVertexBuffer8::QueryInterface(REFIID riid, void **ppvObj)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if (ppvObj == nullptr)
	{
		return E_POINTER;
	}

	if (riid == __uuidof(this) ||
		riid == __uuidof(IUnknown) ||
		riid == __uuidof(Direct3DResource8))
	{
		AddRef();

		*ppvObj = this;

		return S_OK;
	}

	return _proxy->QueryInterface(riid, ppvObj);
}
ULONG STDMETHODCALLTYPE Direct3DVertexBuffer8::AddRef()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	InterlockedIncrement(&_ref);

	return _proxy->AddRef();
}
ULONG STDMETHODCALLTYPE Direct3DVertexBuffer8::Release()
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
HRESULT STDMETHODCALLTYPE Direct3DVertexBuffer8::GetDevice(Direct3DDevice8 **ppDevice)
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
HRESULT STDMETHODCALLTYPE Direct3DVertexBuffer8::SetPrivateData(REFGUID refguid, CONST void *pData, DWORD SizeOfData, DWORD Flags)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->SetPrivateData(refguid, pData, SizeOfData, Flags);
}
HRESULT STDMETHODCALLTYPE Direct3DVertexBuffer8::GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetPrivateData(refguid, pData, pSizeOfData);
}
HRESULT STDMETHODCALLTYPE Direct3DVertexBuffer8::FreePrivateData(REFGUID refguid)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->FreePrivateData(refguid);
}
DWORD STDMETHODCALLTYPE Direct3DVertexBuffer8::SetPriority(DWORD PriorityNew)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->SetPriority(PriorityNew);
}
DWORD STDMETHODCALLTYPE Direct3DVertexBuffer8::GetPriority()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetPriority();
}
void STDMETHODCALLTYPE Direct3DVertexBuffer8::PreLoad()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	_proxy->PreLoad();
}
D3DRESOURCETYPE STDMETHODCALLTYPE Direct3DVertexBuffer8::GetType()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return D3DRTYPE_VERTEXBUFFER;
}
HRESULT STDMETHODCALLTYPE Direct3DVertexBuffer8::Lock(UINT OffsetToLock, UINT SizeToLock, BYTE **ppbData, DWORD Flags)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	if ((Flags & D3DLOCK_DISCARD) != 0)
	{
		D3DVERTEXBUFFER_DESC desc;
		_proxy->GetDesc(&desc);

		if ((desc.Usage & D3DUSAGE_DYNAMIC) == 0)
		{
			Flags ^= D3DLOCK_DISCARD;
		}
	}

	return _proxy->Lock(OffsetToLock, SizeToLock, reinterpret_cast<void **>(ppbData), Flags);
}
HRESULT STDMETHODCALLTYPE Direct3DVertexBuffer8::Unlock()
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->Unlock();
}
HRESULT STDMETHODCALLTYPE Direct3DVertexBuffer8::GetDesc(D3DVERTEXBUFFER_DESC *pDesc)
{
int retaddr = ( int )_ReturnAddress( );
AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

	return _proxy->GetDesc(pDesc);
}
