#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

void __report(const char *assertion, const char *file, unsigned int line)
{
    cerr << file << ":" << line
         << " " << assertion
         << " \033[31mFAILED\033[0m"
         << endl;
}

#define assert(expr)         \
    (static_cast<bool>(expr) \
         ? void(0)           \
         : [] { __report(#expr, __FILE__, __LINE__); asm("int3"); }())
