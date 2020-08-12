#include<iostream>
using namespace std;

struct Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    void helper(Node* root, Node* &head, Node* &tail) {
        if (root == nullptr) return;
        
        Node* lhead, * ltail, * rhead, * rtail;
        lhead = root;
        if (root->left) {
            helper(root->left, lhead, ltail);
            root->left = ltail;
            ltail->right = root;
        }

        rtail = root;
        if (root->right) {
            helper(root->right, rhead, rtail);
            root->right = rhead;
            rhead->left = root;
        }

        head = lhead;
        tail = rtail;
    }

    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;

        Node* head, *tail;
        helper(root, head, tail);
        head->left = tail;
        tail->right = head;

        return head;
    }
};