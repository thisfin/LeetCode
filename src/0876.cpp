//
// Created by 李毅 on 2021/3/27.
//

#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *middleNode(ListNode *head) { // 快慢步进法
        ListNode *slow = head;
        ListNode *fast = head;
        for (; fast != nullptr && fast->next != nullptr;) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
