#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* deleteTargetNode(ListNode* head, ListNode* targetNode) {
		if (head == nullptr)	return {};

		if (targetNode->next != nullptr) {
			ListNode* nextNode = targetNode->next;
			targetNode->val = nextNode->val;
			targetNode->next = nextNode->next;
		}

		else if (head == targetNode) {
			delete targetNode;
			head = nullptr;
			targetNode = nullptr;
		}

		else
		{
			ListNode* tmpNode = head;
			while (tmpNode->next != targetNode)
			{
				tmpNode = tmpNode->next;
			}
			tmpNode->next = nullptr;
			delete targetNode;
			targetNode = nullptr;
		}

		return head;
	}
};