// Chapter4.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// TODO: Reference additional headers your program requires here.

inline const char* const bool_to_string(bool b)
{
	return b ? "true" : "false";
}