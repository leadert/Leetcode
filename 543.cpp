#include<iostream>
#include<algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxLength = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        deep(root);
        return maxLength;
    }

    int deep(TreeNode* root) {
        if (!root)   return 0;
        int lLen = deep(root->left);
        int rLen = deep(root->right);
        maxLength = max(maxLength, lLen + rLen);
        return max(lLen, rLen) + 1;
    }
};