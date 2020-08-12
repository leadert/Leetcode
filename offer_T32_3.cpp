#include<iostream>
#include<vector>
#include<deque>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> ans;
        deque<TreeNode*>  numberQueue;
        numberQueue.push_front(root);
        int flag = 1;
        while (!numberQueue.empty()) {
            int count = numberQueue.size();
            vector<int> levelVec;

            if (flag % 2 == 1) {
                while (count--) {
                    TreeNode* tmpNode = numberQueue.back();
                    numberQueue.pop_back();
                    levelVec.push_back(tmpNode->val);
                    if (tmpNode->left)  numberQueue.push_front(tmpNode->left);
                    if (tmpNode->right)   numberQueue.push_front(tmpNode->right);
                }
                flag = 0;
            }

            if (flag % 2 == 0) {
                while (count--) {
                    TreeNode* tmpNode = numberQueue.front();
                    numberQueue.pop_front();
                    levelVec.push_back(tmpNode->val);
                    if (tmpNode->right)  numberQueue.push_back(tmpNode->right);
                    if (tmpNode->left)   numberQueue.push_back(tmpNode->left);
                }
                flag = 1;
            }

            ans.push_back(levelVec);
        }

        return ans;
    }
};