#pragma once
#include <vector>
#include <Windows.h>

#include "memory.h"
#include "macros.h"

namespace Patterns {
	uintptr_t Scan(const char* sig);
	inline std::vector<int> PatternToByte(const char* sig);
}