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
    bool subTree(TreeNode* A, TreeNode* B) {
        if (B == nullptr)    return true;
        if (A == nullptr)    return false;
        if (A->val != B->val)    return false;
        else    return subTree(A->left, B->left) && subTree(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B)    return false;

        bool result = false;
        if (A != nullptr && B != nullptr) {
            if (A->val == B->val) {
                result = subTree(A->left, B->left) && subTree(A->right, B->right);
            }
            if (!result) result = isSubStructure(A->left, B);
            if (!result) result = isSubStructure(A->right, B);
        }

        return result;
    }
};