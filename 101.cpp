#include<iostream>
#include<vector>
using namespace std;

 // definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    bool ismirror(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        if (p->val == q->val) {
            return ismirror(p->left, q->right) && ismirror(p->right, q->left);
        }

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return ismirror(root->left, root->right);
    }
};