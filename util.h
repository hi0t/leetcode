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

template <typename... Args>
std::vector<typename std::common_type<Args...>::type> mkv(Args &&... args)
{
    return {args...};
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
