#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//转换思路，验证是否是二叉搜索树，左边均小，右边均大；转换为中序遍历，递增问题
class Solution {
private:
    vector<int> res;
public:
    void inOrderTra(TreeNode* root) {
        if (root->left) {
            inOrderTra(root->left);
        }
        res.push_back(root->val);
        if (root->right) {
            inOrderTra(root->right);
        }
    }

    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        inOrderTra(root);
        for (int i = 1; i < res.size(); i++) {
            if (res[i] <= res[i - 1]) {
                return false;
            }
        }
        return true;
    }
};