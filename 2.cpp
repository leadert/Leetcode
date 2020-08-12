#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *Node = new ListNode(0);
		ListNode *head = Node;
		int flag = 0;
		while (l1 && l2) {
			int temp = l1->val + l2->val;
			if ((temp+flag) >= 10) {
				Node->next = new ListNode(temp+flag-10);
				Node = Node->next;
				flag = 1;
			}
			else {
				Node->next = new ListNode(temp + flag);
				Node = Node->next;
				flag = 0;
			}
			l1 = l1->next;
			l2 = l2->next;
		}

		if (l1) {
			while (l1) {
				if ((l1->val + flag) >= 10) {
					Node->next = new ListNode(l1->val + flag - 10);
					Node = Node->next;
					flag = 1;
				}
				else {
					Node->next = new ListNode(l1->val + flag);
					Node = Node->next;
					flag = 0;
				}
				l1 = l1->next;
			}
		}

		else if (l2) {
			while (l2) {
				if ((l2->val + flag) >= 10) {
					Node->next = new ListNode(l2->val + flag - 10);
					Node = Node->next;
					flag = 1;
				}
				else {
					Node->next = new ListNode(l2->val + flag);
					Node = Node->next;
					flag = 0;
				}
				l2 = l2->next;
			}
		}

		if (flag == 1) {
			Node->next = new ListNode(1);
		}
		return head->next;
	}
};


//int main() {	
//	ListNode* l1 = new ListNode(2);
//	ListNode* head1 = l1;
//	l1->next = new ListNode(4);
//	l1 = l1->next;
//	l1->next = new ListNode(3);
//	l1 = l1->next;
//	l1->next = new ListNode(9);
//	l1 = l1->next;
//
//	ListNode* l2 = new ListNode(5);
//	ListNode* head2 = l2;
//	l2->next = new ListNode(6);
//	l2 = l2->next;
//	l2->next = new ListNode(4);
//	l2 = l2->next;
//	
//	Solution a;
//	ListNode* ret = a.addTwoNumbers(head1, head2);
//	
//	while (ret) {
//		cout << ret->val;
//		ret = ret->next;
//	}
//	return 0;
//}

