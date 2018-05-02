#pragma once

#include "Types.hpp"

class Console
{
public:
	Console() = delete;

	static void print(const string& message);
	static void pause();
};