#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* lastKNode(ListNode* head, int k) {
		if (head == nullptr || k == 0)	return nullptr;
		ListNode* fastNode = head;
		while (k) {
			if (fastNode)	fastNode = fastNode->next;
			else return nullptr;
			k--;
		}

		ListNode* targetNode = head;
		while (fastNode){
			fastNode = fastNode->next;
			targetNode = targetNode->next;
		}

		return targetNode;
	}
};