#include<iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) {
            return false;
        }
        ListNode* fast = head;
        ListNode* low = head;

        while (fast->next) {
            fast = fast->next;
            if (fast->next) {
                fast = fast->next;
            }
            if (fast == low) {
                return true;
            }

            low = low->next;
        }

        return false;
    }
};