#ifndef LRINGNOISELIB_H
#define LRINGNOISELIB_H

#include <lua.h>

#define RINGNOISE_LIBNAME "ringnoise"
#define RINGNOISE_LUAT "lua.ringnoise"

extern int luaopen_ringnoise(lua_State *L);

#endif
