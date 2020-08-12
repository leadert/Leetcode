// ÖØ½¨¶þ²æÊ÷
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	unordered_map<int, int> index;
	TreeNode* bulidPartTree(vector<int>& preOrder, vector<int>& inOrder, int preLeft, int preRight, int inLeft, int inRight) {
		if (preLeft > preRight)	return nullptr;
		
		TreeNode* root = new TreeNode(preOrder[preLeft]);
		int inOrderRootIndex = index[preOrder[preLeft]];
		int leftTreeCount = inOrderRootIndex - inLeft;
		root->left = bulidPartTree(preOrder, inOrder, preLeft + 1, preLeft + leftTreeCount, inLeft, leftTreeCount - 1);
		root->right = bulidPartTree(preOrder, inOrder, preLeft + leftTreeCount + 1, preRight, inOrderRootIndex + 1, inRight);

		return root;
	}

	TreeNode* reBulidTree(vector<int>& preOrder, vector<int>& inOrder) {
		if (preOrder.empty() || inOrder.empty() || preOrder.size() != inOrder.size())
			return nullptr;

		int n = preOrder.size();
		for (int i = 0; i < n; i++) {
			index[inOrder[i]] = i;
		}

		TreeNode* root = bulidPartTree(preOrder, inOrder, 0, n - 1, 0, n - 1);
	}
};