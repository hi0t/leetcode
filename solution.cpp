#include "util.h"
#include <bits/stdc++.h>

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        stack<ListNode *> s;
        auto dummy = new ListNode();
        dummy->next = head;
        auto node = dummy;
        while (node != nullptr) {
            s.push(node);
            node = node->next;
        }
        for (int i = 0; i < n; i++) {
            s.pop();
        }

        node = s.top();
        if (node->next != nullptr) {
            node->next = node->next->next;
        }
        return dummy->next;
    }
};

int main()
{
    Solution s;

    auto root = new ListNode(1);
    root->next = new ListNode(2);
    /*auto cycle = root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = new ListNode(-5);
    root->next->next->next->next->next = cycle;*/

    ASSERT(s.removeNthFromEnd(root, 2));

    return 0;
}
