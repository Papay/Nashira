// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" {
#include "../Libs/lua-5.1.5/include/lauxlib.h"
#include "../Libs/lua-5.1.5/include/lua.h"
}

static char lib_version[] = "QUIK Lua Connector version 0.1";

static int forLua_GetLuaConnectorVersion(lua_State *L) {
    // возвращаем одно значение
    lua_pushfstring(L, lib_version);
    return(1);
}

static struct luaL_reg ls_lib[] = {
    { "GetLuaConnectorVersion", forLua_GetLuaConnectorVersion },
{ NULL, NULL }
};

extern "C" LUALIB_API int luaopen_QLuaConnector(lua_State *L) {
    luaL_openlib(L, "QLuaConnector", ls_lib, 0);
    return 0;
}
