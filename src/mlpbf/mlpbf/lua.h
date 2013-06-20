#pragma once

#include <lua5.2/lua.hpp>

namespace bf
{
	namespace lua
	{
		void init();
		void cleanup();
	
		lua_State * state();
	}
}
