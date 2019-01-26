#include "lringnoiselib.h"
#include <ringnoise.h>
#include <math.h>

#ifdef __cplusplus
  #include <lua.hpp>
#else
  #include <lua.h>
  #include <lualib.h>
  #include <lauxlib.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int ringnoise_perlin4(lua_State *L)
{
	float x = luaL_checknumber(L, 1);
	float y = luaL_checknumber(L, 2);
	float z = luaL_checknumber(L, 3);
	float w = luaL_checknumber(L, 4);
	float frequency = luaL_checknumber(L, 5);
	struct vector4 point = {x, y, z, w};
	lua_pushnumber(L, rn_perlin4(point, frequency));
	return 1;
}

static int ringnoise_perlinsum4(lua_State *L)
{
	float x = luaL_checknumber(L, 1);
	float y = luaL_checknumber(L, 2);
	float z = luaL_checknumber(L, 3);
	float w = luaL_checknumber(L, 4);
	float frequency = luaL_checknumber(L, 5);
	int octaves = luaL_checkinteger(L, 6);
	float lacunarity = luaL_checknumber(L, 7);
	float persistence = luaL_checknumber(L, 8);
	struct vector4 point = {x, y, z, w};
	lua_pushnumber(L, rn_perlinsum4(point, frequency, octaves, lacunarity, persistence));
	return 1;
}

static int ringnoise_perlinring2(lua_State *L)
{
	float x = luaL_checknumber(L, 1);
	float y = luaL_checknumber(L, 2);
	float offset = luaL_checknumber(L, 3);
	float frequency = luaL_checknumber(L, 4);
	lua_pushnumber(L, rn_perlinring2(x, y, offset, frequency));
	return 1;
}

static int ringnoise_perlinringsum2(lua_State *L)
{
	float x = luaL_checknumber(L, 1);
	float y = luaL_checknumber(L, 2);
	float offset = luaL_checknumber(L, 3);
	float frequency = luaL_checknumber(L, 4);
	int octaves = luaL_checkinteger(L, 5);
	float lacunarity = luaL_checknumber(L, 6);
	float persistence = luaL_checknumber(L, 7);
	lua_pushnumber(L, rn_perlinringsum2(x, y, offset, frequency, octaves, lacunarity, persistence));
	return 1;
}

static const struct luaL_Reg lringnoiselib_f [] = {
	{"perlin4", ringnoise_perlin4},
	{"perlinsum4", ringnoise_perlinsum4},
	{"perlinring2", ringnoise_perlinring2},
	{"perlinringsum2", ringnoise_perlinringsum2},
	{NULL, NULL}
};

int luaopen_ringnoise(lua_State *L)
{
  luaL_newlib(L, lringnoiselib_f);
	return 1;
}

#ifdef __cplusplus
}
#endif
