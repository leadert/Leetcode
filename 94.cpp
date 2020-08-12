#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private: 
    vector<int> res;

public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root->left) {
            inorderTraversal(root->left);
        }

        res.push_back(root->val);

        if (root->right) {
            inorderTraversal(root->right);
        }

        return res;
    }
};