#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Node = new ListNode(0);
        Node->next = head;
        ListNode* First = Node;

        for (int i = 0; i < n; i++) {
            Node = Node->next;
        }
        
        ListNode* left = First;
        while (Node->next) {
            Node = Node->next;
            left = left->next;
        }
        left->next = left->next->next;
        return First->next;
    }
};

//int main() {
//    ListNode* l1 = new ListNode(1);
//    ListNode* head1 = l1;
//    l1->next = new ListNode(2);
//    l1 = l1->next;
//    l1->next = new ListNode(3);
//    l1 = l1->next;
//    l1->next = new ListNode(4);
//    l1 = l1->next;
//    l1->next = new ListNode(5);
//
//    ListNode* ret = Solution().removeNthFromEnd(head1, 2);
//    while (ret) {
//        cout << ret->val;
//        ret = ret->next;
//    }
//    return 0;
//}