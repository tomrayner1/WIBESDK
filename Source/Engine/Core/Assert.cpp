#include "Core/StdAfx.h"

#include "Assert.h"

#include <DetectPlatform.h>

#include <iostream>
#if IsWin()
#	include <intrin.h>
#endif

bool EnsureDebug();

void brAssert(bool eval, const char* msg)
{
	if (!EnsureDebug())
		return;

	std::cout << "brAssert() called: " << msg << "\n";

	#if IsWin()
	__debugbreak();
	#endif
}

void kAssert(bool eval)
{

}

//
// Purpose: Only let asserts fire on debug mode !
//
bool EnsureDebug()
{
	#ifdef _DEBUG
	return true;
	#else
	return false;
	#endif
}