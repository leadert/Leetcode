// 从尾到头打印链表
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};


class Solution {
public:
    vector<int> ansVec;

    void printList(ListNode* head) {
        if (head == nullptr) return;

        printList(head->next);
        ansVec.push_back(head->val);
    }

    vector<int> reversePrint(ListNode* head) {
        if (head == nullptr) return {};
        printList(head);
        return ansVec;
    }
};


//int main() {
//	ListNode* head = new ListNode(1);
//	ListNode* l1 = new ListNode(2);
//	ListNode* l2 = new ListNode(4);
//	ListNode* l3 = new ListNode(3);
//	ListNode* l4 = new ListNode(5);
//
//	head->next = l1;
//	l1->next = l2;
//	l2->next = l3;
//	l3->next = l4;
//
//	vector<int> ans = Solution().reversePrint(head);
//  for (auto x : ans)
//      cout << x << " ";
//	return 0;
//}