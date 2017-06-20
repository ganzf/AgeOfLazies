#ifndef		LUAFUNC_HPP_
# define	LUAFUNC_HPP_

extern "C" {
# include "lualib/lua.h"
# include "lualib/lauxlib.h"
# include "lualib/lualib.h"
}

int		AiPlayer_print(lua_State *L);
int		AiPlayer_getWood(lua_State *L);
int		AiPlayer_getMaxWood(lua_State *L);
int		AiPlayer_getStone(lua_State *L);
int		AiPlayer_getMaxStone(lua_State *L);
int		AiPlayer_getFood(lua_State *L);
int		AiPlayer_getMaxFood(lua_State *L);
int		AiPlayer_getGold(lua_State *L);
int		AiPlayer_getMaxGold(lua_State *L);
int		AiPlayer_getCostBuilding(lua_State *L);
int		AiPlayer_getCostUnit(lua_State *L);
int		AiPlayer_getNbUnit(lua_State *L);
int		AiPlayer_collect(lua_State *L);
int		AiPlayer_createUnit(lua_State *L);
int		AiPlayer_createBuilding(lua_State *L);
int		AiPlayer_checkFrame(lua_State *L);
int		AiPlayer_getNbCollector(lua_State *L);
int		AiPlayer_getNbWarrior(lua_State *L);

#endif		/* !LUAFUNC_HPP_ */
