//
// Created by 李毅 on 2021/2/25.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return node(l1, l2, 0);
    }

    ListNode *node(ListNode *l1, ListNode *l2, int defaultValue) {
        ListNode *result = new ListNode();
        int value = defaultValue + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        result->val = value % 10;
        int nextValue = value / 10;
        ListNode *n1 = l1 ? l1->next : nullptr;
        ListNode *n2 = l2 ? l2->next : nullptr;
        if (nextValue || n1 || n2) {
            result->next = node(n1, n2, nextValue);
        }
        return result;
    }
};
