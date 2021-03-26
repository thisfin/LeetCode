//
// Created by 李毅 on 2021/3/27.
//

#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }
        int count = 0;
        for (ListNode *temp = head;; temp = temp->next) {
            count++; // count
            if (temp->next == nullptr) {
                temp->next = head; // 尾部连接
                break;
            }
        }
        ListNode *result = head;
        int index = count - (k % count);
        int i = 0;
        for (ListNode *temp = head;; temp = temp->next) {
            if (i++ == index - 1) {
                result = temp->next; // 找到头
                temp->next = nullptr; // 断开环
                break;
            }
        }
        return result;
    }
};
