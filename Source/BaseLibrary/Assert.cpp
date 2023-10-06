#include "Assert.h"
#include "DetectPlatform.h"

#include <iostream>

#if IsWin()
#	include <intrin.h>
#endif

bool brAssert(bool eval, const char* msg)
{
	#ifndef _DEBUG
	return false;
	#endif

	if (eval)
		return false;

	std::cout << "brAssert() called: " << msg << "\n";

	#if IsWin()
	__debugbreak();
	#endif

	return true;
}