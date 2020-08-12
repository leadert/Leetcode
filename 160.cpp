#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL)   return NULL;
        if (headB == NULL)   return NULL;

        int lenA = 0;
        ListNode* tmp = headA;
        while (tmp) {
            lenA++;
            tmp = tmp->next;
        }

        int lenB = 0;
        tmp = headB;
        while (tmp) {
            lenB++;
            tmp = tmp->next;
        }

        tmp = (lenA < lenB ? headB : headA);
        if (tmp == headB) {
            headB = headA;
            headA = tmp;
        }

        int dis = lenA < lenB ? lenB - lenA : lenA - lenB;
        while (dis > 0) {
            headA = headA->next;
            dis--;
        }
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        if (headA) return headA;
        else    return NULL;
    }
};


//int main() {
//    ListNode* headA = new ListNode(1);
//    ListNode* a2 = new ListNode(9);
//
//    ListNode* headB = new ListNode(3);
//
//
//    ListNode* c1 = new ListNode(2);
//    ListNode* c2 = new ListNode(4);
//
//    headA->next = a2;
//    a2->next = c1;
//    c1->next = c2;
//    headB->next = c1;
//
//    ListNode* joinNode = Solution().getIntersectionNode(headA, headB);
//    cout << joinNode->val << endl;
//    return 0;
//}