#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)  return NULL;

        ListNode* left = head;
        ListNode* right = head;
        while (right && right->next) {
            right = right->next;
            if (right && right->val != left->val) {
                left->next = right;
                left = right;
            }
        }
        left->next = NULL;
        return head;
    }
};