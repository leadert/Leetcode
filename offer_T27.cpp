#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}  
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)   return nullptr;
        TreeNode* tmpNode = root->left;
        root->left = root->right;
        root->right = tmpNode;
        if (root->left)  mirrorTree(root->left);
        if (root->right) mirrorTree(root->right);

        return root;
    }
};
