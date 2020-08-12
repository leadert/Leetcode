#include<iostream>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	queue<TreeNode*> nodeQueue;
public:
	vector<int> rightSideView(TreeNode* root) {
		if (root == NULL)	return{};

		vector<int> ret;
		nodeQueue.push(root);
		while (!nodeQueue.empty()) {
			int levelNodeCount = nodeQueue.size();

			while (levelNodeCount>0) {
				TreeNode* tmp = nodeQueue.front();
				nodeQueue.pop();
				if (tmp->left) nodeQueue.push(tmp->left);
				if (tmp->right) nodeQueue.push(tmp->right);
				levelNodeCount--;
				if (levelNodeCount == 0) {
					ret.push_back(tmp->val);
					break;
				}
			}
		}

		return ret;
	}
};