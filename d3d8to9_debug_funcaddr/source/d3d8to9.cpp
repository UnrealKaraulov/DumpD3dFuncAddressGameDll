/**
 * Copyright (C) 2015 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/d3d8to9#license
 */

#include "d3d8to9.hpp"


#ifndef D3D8TO9NOLOG
 // Very simple logging for the purpose of debugging only.
std::ofstream LOG;
#endif


struct NewGameDllFuncD3D
{
	std::string FuncName;
	int FuncAddr;
};


std::vector<NewGameDllFuncD3D> funclist;

HMODULE GameDll = NULL;

HMODULE GetModuleFromAddress( int addr )
{
	HMODULE hModule = NULL;
	GetModuleHandleEx(
		GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
		( LPCTSTR )addr,
		&hModule );

	return hModule;
}

void AddNewFunctionAddrForGameDll( const char * funcname, int funcaddr )
{
	for ( NewGameDllFuncD3D dd : funclist )
	{
		if ( dd.FuncName == funcname )
		{
			if ( dd.FuncAddr == funcaddr )
			{
				return;
			}

		}

	}

	NewGameDllFuncD3D newdata = NewGameDllFuncD3D( );
	newdata.FuncName = funcname;
	newdata.FuncAddr = funcaddr;
	funclist.push_back( newdata );
	if ( !GameDll )
	{
		GameDll = GetModuleHandle( "Game.dll" );
	}

	HMODULE UnknownModule = GetModuleFromAddress( funcaddr );

	if ( UnknownModule == GameDll )
	{
		LOG << "Function \"" << funcname << "\" addr: Game.Dll+0x" << std::hex << ( funcaddr - ( int )GameDll ) << std::endl;
	}

}

extern "C" Direct3D8 *WINAPI Direct3DCreate8(UINT SDKVersion)
{
	int retaddr = ( int )_ReturnAddress( );
	AddNewFunctionAddrForGameDll( __FUNCTION__, retaddr );

#ifndef D3D8TO9NOLOG
	LOG.open("d3d8.log", std::ios::trunc);

	if (!LOG.is_open())
	{
		MessageBoxA(nullptr, "Failed to open debug log file \"d3d8.log\"!", nullptr, MB_ICONWARNING);
	}

	LOG << "Redirecting '" << "Direct3DCreate8" << "(" << SDKVersion << ")' ..." << std::endl;
	LOG << "> Passing on to 'Direct3DCreate9':" << std::endl;
#endif

	IDirect3D9 *const d3d = Direct3DCreate9(D3D_SDK_VERSION);

	if (d3d == nullptr)
	{
		return nullptr;
	}

	return new Direct3D8(d3d);
}
