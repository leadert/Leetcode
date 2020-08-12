#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = robHome(root);
        return max(res[0], res[1]);
    }

    vector<int>& robHome(TreeNode* root) {
        vector<int> result(2, 0);

        if (root == NULL)
            return result;

        vector<int> left = robHome(root->left);
        vector<int> right = robHome(root->right);
        result[0] = max(left[0], left[1]) + max(right[0], right[1]);
        result[1] = left[0] + right[0] + root->val;

        return result;
    }
    /*int rob(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL) {
            return root->val;
        }
        else if (root->left == NULL) {
            return max(root->val + rob(root->right->left) + rob(root->right->right), rob(root->right));
        }
        else if (root->right == NULL) {
            return max(root->val + rob(root->left->left) + rob(root->left->right), rob(root->left));
        }
        else {
            return max(root->val + rob(root->left->left) + rob(root->left->right) + rob(root->right->left) + rob(root->right->right), rob(root->left) + rob(root->right));
        }
    }*/
};