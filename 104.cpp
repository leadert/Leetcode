//求树的深度，思路1：栈；元素弹出前比较栈的高度（本代码思路）
//思路2：利用层次遍历，看vector<vector<int>>中共有几个元素（借助102题思路）

#include<iostream>
#include<vector>
#include<stack>
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
    int maxDepth(TreeNode* root) {
        if (!root)   return 0;

        int maxTreeDepth = 1;
        stack<TreeNode*> treeNode;
        treeNode.push(root);

        while (!treeNode.empty()) {
            TreeNode* topNode = treeNode.top();
            if (topNode->left) {
                treeNode.push(topNode->left);
                topNode->left = NULL;
                continue;
            }
            else if (topNode->right) {
                treeNode.push(topNode->right);
                topNode->right = NULL;
                continue;
            }
            else {
                maxTreeDepth = max(maxTreeDepth, (int)treeNode.size());
                treeNode.pop();
            }
        }

        return maxTreeDepth;
    }
};