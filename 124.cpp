#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int maxValue = INT16_MIN;
public:
	int maxPathSum(TreeNode* root) {
		if (root == NULL)	return 0;
		dfTree(root);
		return maxValue;
	}

	int dfTree(TreeNode* root) {
		if (root == NULL)	return 0;
		int leftValue = max(0, dfTree(root->left));
		int rightValue = max(0, dfTree(root->right));
		maxValue = max(maxValue, root->val + leftValue + rightValue);
		return root->val + max(leftValue, rightValue);
	}
};