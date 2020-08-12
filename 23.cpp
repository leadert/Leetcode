#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}   
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* Node = new ListNode(0);
        ListNode* head = Node;

        if (lists.size() == 0) return NULL;

        vector<ListNode*> demo(lists.size(), new ListNode(INT16_MAX));
        while (lists != demo) {
            int minIndex = 0;
            int minValue = INT16_MAX;
            for (int i = 0; i < lists.size(); i++) {
                if (!lists[i]) lists[i] = new ListNode(INT16_MAX);
                if (lists[i]->val < minValue) {
                    minValue = lists[i]->val;
                    minIndex = i;
                }
            }
            if (minValue == INT16_MAX) break;
            Node->next = lists[minIndex];
            if (lists[minIndex]->next) lists[minIndex] = lists[minIndex]->next;
            else lists[minIndex] = new ListNode(INT16_MAX);
            Node = Node->next;
        }
        return head->next;
    }
};

//int main() {
//    vector<ListNode*> lists;
//
//    ListNode* l1 = new ListNode(1);
//    ListNode* head1 = l1;
//    l1->next = new ListNode(4);
//    l1 = l1->next;
//    l1->next = new ListNode(5);
//
//    ListNode* l2 = new ListNode(1);
//    ListNode* head2 = l2;
//    l2->next = new ListNode(3);
//    l2 = l2->next;
//    l2->next = new ListNode(4);
//
//    ListNode* l3 = new ListNode(2);
//    ListNode* head3 = l3;
//    l3->next = new ListNode(6);
//    
//    lists.push_back(head1);
//    lists.push_back(head2);
//    lists.push_back(head3);
//
//    ListNode* ret = Solution().mergeKLists(lists);
//    while (ret) {
//        cout << ret->val << " ";
//        ret = ret->next;
//    }
//}