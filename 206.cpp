#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = NULL;
		ListNode* curr = head;

		while (curr) {
			ListNode* nextNode = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextNode;
		}

		return prev;
	}
};