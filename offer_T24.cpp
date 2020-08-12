#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)   return nullptr;

        ListNode* tail = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = tail;
            tail = head;
            head = nextNode;
        }

        return tail;
    }
};