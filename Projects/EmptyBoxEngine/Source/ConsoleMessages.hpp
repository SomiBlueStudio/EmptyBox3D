#pragma once

#include "Console.hpp"

namespace io
{
	#ifdef WINDOWS_PLATFORM

	#define TRACE(message, type) Console::trace(message, __FILE__, __FUNCTION__, __LINE__, type)
	#define PRINT(message, type) Console::print(message, type)

	#define PAUSE() Console::pause()

	#endif
}