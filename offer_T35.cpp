#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    void CloneNode(Node* head) {
        if (head == nullptr) return;

        Node* tmpNode = head;
        while (tmpNode) {
            Node* insertNode = new Node(0);
            insertNode->val = tmpNode->val;
            insertNode->next = tmpNode->next;
            insertNode->random = nullptr;

            tmpNode->next = insertNode;
            tmpNode = insertNode->next;
        }
    }

    void CloneRandom(Node* head) {
        Node* tmpNode = head;
        while (tmpNode) {
            Node* clonedNode = tmpNode->next;
            if (tmpNode->random) {
                clonedNode->random = tmpNode->random->next;
            }
            tmpNode = clonedNode->next;
        }
    }

    Node* reconnectList(Node* head) {
        Node* tmpNode = head;
        Node* newHead = nullptr;
        Node* newCloneNode = nullptr;

        if (tmpNode) {
            newHead = newCloneNode = tmpNode->next;
            tmpNode->next = newCloneNode->next;
            tmpNode = tmpNode->next;
        }

        while (tmpNode) {
            newCloneNode->next = tmpNode->next;
            newCloneNode = newCloneNode->next;
            tmpNode->next = newCloneNode->next;
            tmpNode = tmpNode->next;
        }

        return newHead;
    }

    Node* copyRandomList(Node* head) {
        CloneNode(head);
        CloneRandom(head);
        return reconnectList(head);
    }
};