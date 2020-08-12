#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countPath(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        sum = sum - root->val;
        int result = sum == 0 ? 1 : 0;
        return result + countPath(root->left, sum) + countPath(root->right, sum);
    }

    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;

        int result = countPath(root, sum);
        int a = pathSum(root->left, sum);
        int b = pathSum(root->right, sum);

        return result + a + b;
    }
};