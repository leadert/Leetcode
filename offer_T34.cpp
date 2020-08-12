#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val) :val(_val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<vector<int>>	ans;

	void dfs(TreeNode* root, int sum, vector<int>& sub_path) {
		if (root == nullptr) 
			return;

		sub_path.emplace_back(root->val);
		if (sum == root->val && root->left == nullptr && root->right == nullptr) {
			ans.emplace_back(sub_path);
		}

		dfs(root->left, sum - root->val, sub_path);
		dfs(root->right, sum - root->val, sub_path);
		sub_path.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == nullptr)	return ans;
		vector<int>	sub_path;
		dfs(root, sum, sub_path);
		return ans;
	}
};


//int main() {
//	TreeNode* head = new TreeNode(5);
//	TreeNode* node2 = new TreeNode(4);
//	TreeNode* node3 = new TreeNode(8);
//	TreeNode* node4 = new TreeNode(11);
//	TreeNode* node5 = new TreeNode(13);
//	TreeNode* node6 = new TreeNode(4);
//	TreeNode* node7 = new TreeNode(7);
//	TreeNode* node8 = new TreeNode(2);
//	TreeNode* node9 = new TreeNode(5);
//	TreeNode* node10 = new TreeNode(1);
//
//	head->left  = node2;
//	head->right = node3;
//	node2->left = node4;
//	node3->left = node5;
//	node3->right = node6;
//	node4->left = node7;
//	node4->right = node8;
//	node6->left = node9;
//	node6->right = node10;
//
//	vector<vector<int>>	result = Solution().pathSum(head, 22);
//	for (auto vec : result) {
//		for (auto num : vec) {
//			cout << num << " ";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}