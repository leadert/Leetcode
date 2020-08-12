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
        if (root->left == nullptr && root->right == nullptr) return 1;
        int leftDeep = 0, rightDeep = 0;
        if (root->left)  leftDeep = dfs(root->left);
        if (root->right) rightDeep = dfs(root->right);

        return max(leftDeep, rightDeep) + 1;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr)   return 0;
        int ans = dfs(root);

        return ans;
    }
};