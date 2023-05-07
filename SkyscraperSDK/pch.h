#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <robin_hood.h>
#include <array>
#include <xmmintrin.h>
#include <string>
#include <vector>
#include <memory>
#include <atomic>
#include <unordered_map>
#include <map>
#include <forward_list>
#include <nanoflann.h>
#include <deque>
#include <functional>

#include <Minhook.h>
#pragma comment(lib,"libMinHook.x64.lib")

#include "framework.h"

#define LOG(a) std::cout << a << std::endl;
#define VERSION 001
#define SHOOK __fastcall
#define SCMD __extern

#endif // PCH_H