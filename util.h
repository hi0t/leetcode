#pragma once

#include <iostream>

using namespace std;

void __report(const char *assertion, bool valid)
{
    cerr << assertion << '\t'
         << (valid ? "\033[32mPASSED\033[0m" : "\033[31mFAILED\033[0m")
         << endl;
}

#define ASSERT(expr)                \
    (static_cast<bool>(expr)        \
            ? __report(#expr, true) \
            : [] { __report(#expr, false); asm("int3"); }())

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};
