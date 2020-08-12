#include<iostream>
#include<vector>
#include<queue>
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
        if (root == NULL)  return {};

        vector<vector<int>> ret;
        queue<TreeNode*> levelNodeQueue;
        levelNodeQueue.push(root);
        while (!levelNodeQueue.empty()) {
            int count = levelNodeQueue.size();
            vector<int> tmp;
            while (count--) {
                TreeNode* node = levelNodeQueue.front();
                tmp.push_back(node->val);
                levelNodeQueue.pop();
                if (node->left) levelNodeQueue.push(node->left);
                if (node->right) levelNodeQueue.push(node->right);
            }
            ret.push_back(tmp);
        }

        return ret;
    }
};