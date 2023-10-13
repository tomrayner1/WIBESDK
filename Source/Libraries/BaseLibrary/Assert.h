#pragma once

// Because writing brAssert(false) is dumb
bool brAssert(bool eval = false, const char* msg = "");