#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* Node = new ListNode(0);
        ListNode* head = Node;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                Node->next = l1;
                l1 = l1->next;
                Node = Node->next;
            }
            else {
                Node->next = l2;
                l2 = l2->next;
                Node = Node->next;
            }
        }

        if (l1) {
            Node->next = l1;
            l1 = l1->next;
            Node = Node->next;
        }

        else if (l2) {
            Node->next = l2;
            l2 = l2->next;
            Node = Node->next;
        }

        return head->next;
    }
};


//int main() {
//    ListNode* l1 = new ListNode(1);
//    ListNode* head1 = l1;
//    l1->next = new ListNode(2);
//    l1 = l1->next;
//    l1->next = new ListNode(4);
//    l1 = l1->next;
//
//    ListNode* l2 = new ListNode(1);
//    ListNode* head2 = l2;
//    l2->next = new ListNode(3);
//    l2 = l2->next;
//    l2->next = new ListNode(4);
//    l2 = l2->next;
//
//    ListNode* ret = Solution().mergeTwoLists(head1, head2);
//    while (ret) {
//        cout << ret->val << " ";
//        ret = ret->next;
//    }
//}