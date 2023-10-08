/// Trigger warning: Extreme use of the preprocessor
#pragma once

// ==============================
// Defines:

#define IsPC() false
#define IsPhone() false
//#define IsConsole() false

#define IsWin() false

#define IsWin32() false
#define IsWin64() false

#define IsApple() false

#define IsAppleSimulator() false
#define IsAppleMacCatalyst() false
#define IsAppleIPhone() false
#define IsAppleMac() false

#define IsAndroid() false
#define IsLinux() false
// ==============================

#define BL_PLATFORM_DETECTED

#if defined(_WIN32)
#	undef IsPC
#	define IsPC() true
#	undef IsWin
#	define IsWin() true
#	ifdef _WIN64
#		undef IsWin64
#		define IsWin64() true
#	else
#		undef IsWin32
#		define IsWin32() true
#	endif
#elif defined(__APPLE__)
#	include <TargetConditionals.h>
#	undef IsApple
#	define IsApple() true
#	if defined(TARGET_IPHONE_SIMULATOR)
#		undef IsAppleSimulator
#		define IsAppleSimulator() true
#	elif defined(TARGET_OS_MACCATALYST)
#		undef IsAppleMacCatalyst
#		define IsAppleMacCatalyst() true
#	elif defined(TARGET_OS_IPHONE)
#		undef IsPhone
#		define IsPhone() true
#		undef IsAppleIPhone
#		define IsAppleIPhone() true
#	elif defined(TARGET_OS_MAC)
#		undef IsPC
#		define IsPC() true
#		undef IsAppleMac
#		define IsAppleMac() true
#	else
#		undef BL_PLATFORM_DETECTED
#		error "Failed to detect apple platform!"
#	endif
#elif defined(__ANDROID__)
#	undef IsPhone
#	define IsPhone() true
#	undef IsAndroid
#	define IsAndroid() true
#elif defined(__linux__)
#	undef IsPC
#	define IsPC() true
#	undef IsLinux
#	define IsLinux() true
//#elif defined(__unix__)
#else
#	undef BL_PLATFORM_DETECTED
#	error "Failed to detect platform!"
#endif