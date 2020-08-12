//寻找环的入口点

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head)   return NULL;
        ListNode* fast = head;
        ListNode* low = head;
        while (fast->next) {
            fast = fast->next;
            if (fast->next) {
                fast = fast->next;
            }
            else {
                return NULL;
            }
            low = low->next;
            if (fast == low) {
                break;
            }
        }
        if (!fast->next)   return NULL;
        fast = head;
        while (fast != low) {
            fast = fast->next;
            low = low->next;
        }

        return fast;
    }
};