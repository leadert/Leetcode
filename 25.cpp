#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail) {
		ListNode* reTail = head;
		ListNode* last = NULL;
		while (head != tail) {
			ListNode* nex = head->next;
			head->next = last;
			last = head;
			head = nex;
		}
		head->next = last;

		return { head, reTail };
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* pre = new ListNode(0);
		pre->next = head;
		ListNode* hair = pre;
		
		while (head) {
			ListNode* tail = pre;
			for (int i = 0; i < k; i++) {
				tail = tail->next;
				if (!tail) {
					return hair->next;
				}
			}
			ListNode* nex = tail->next;
			pair<ListNode*, ListNode*> ret = reverseList(head, tail);
			ListNode* tHead = ret.first;
			ListNode* tTail = ret.second;
			pre->next = tHead;
			tTail->next = nex;
			pre = tTail;
			head = nex;
		}

		return hair->next;
	}
};

//int main() {
//	ListNode* node1 = new ListNode(1);
//	ListNode* node2 = new ListNode(2);
//	ListNode* node3 = new ListNode(3);
//	ListNode* node4 = new ListNode(4);
//	ListNode* node5 = new ListNode(5);
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//
//	ListNode* head = Solution().reverseKGroup(node1, 3);
//	while (head)
//	{
//		cout << head->val << " ";
//		head = head->next;
//	}
//}