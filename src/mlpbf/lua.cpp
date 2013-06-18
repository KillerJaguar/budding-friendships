#include "mlpbf/global.h"
#include "mlpbf/lua.h"

namespace bf
{
namespace lua
{

/***************************************************************************/

int lua_showText( lua_State * l )
{
	const char * ctext = luaL_checkstring( l, 1 );
	const char * cspeaker = luaL_optstring( l, 2, NULL );
	
	bf::showText( ctext, std::string( cspeaker != NULL ? cspeaker : "" ) );
	return 0;
}

static const struct luaL_Reg testLib[] = 
{
	{ "showText", lua_showText },
	{ NULL, NULL },
};

/***************************************************************************/

lua_State * newState()
{
	// create lua state
	lua_State * l = luaL_newstate();
	luaL_openlibs( l );
	
	// register custom libraries
	luaL_newlib( l, testLib );
	
	return l;
}

/***************************************************************************/

} // namespace lua

} // namespace bf