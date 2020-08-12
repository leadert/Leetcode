#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    stack<TreeNode*> tmp;
public:
    void inorderTra(TreeNode* root) {
        if (root->left)  inorderTra(root->left);
        tmp.push(root);
        if (root->right) inorderTra(root->right);
    }

    TreeNode* convertBST(TreeNode* root) {
        if (!root)   return NULL;
        inorderTra(root);

        TreeNode* lastNode = tmp.top();   //最后一个元素不用累加
        int sum = lastNode->val;
        tmp.pop();
        while (!tmp.empty()) {
            TreeNode* tmpNode = tmp.top();
            tmpNode->val += sum;
            sum = tmpNode->val;
            tmp.pop();
        }
        return root;
    }
};