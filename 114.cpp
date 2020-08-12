//再练习
//二叉树展开为链表
//递归，左子树展开、右子树展开，左子树链表插入根与右子树链表之间，左子树设为空

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;

        while (root->right) {
            root = root->right;
        }

        root->right = tmp;
    }
};