#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;

		if (!head)	return nullptr;
		while (fast->next) {
			fast = fast->next;
			if (fast->next)	fast = fast->next;
			else return nullptr;
			slow = slow->next;
			if (fast == slow)	break;
		}

		if (!fast->next)	return nullptr;
		fast = head;
		while (fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}

		return fast;
	}
};