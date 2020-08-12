#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int dfs(TreeNode* root) {
        if (root == nullptr)   return 0;
        int leftHigh = dfs(root -> left);
        int rightHigh = dfs(root->right);
        if (leftHigh == -1 || rightHigh == -1 || abs(leftHigh - rightHigh) > 1)
            return -1;

        return max(leftHigh, rightHigh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr)   return true;
        else return dfs(root) >= 1;
    }
};