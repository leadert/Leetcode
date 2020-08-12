#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	TreeNode(int x) :val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution {
public:
	TreeNode* nextNode(TreeNode* root, TreeNode* target) {
		if (root == nullptr)	return nullptr;
		if (target->right) {
			TreeNode* tmpNode = target->right;
			while (tmpNode->left) {
				tmpNode = tmpNode->left;
			}
			return tmpNode;
		}

		else {
			if (target->parent->left == target)
			{
				return target->parent;
			}
			else
			{
				while (target->parent->right == target) {
					target = target->parent;
				}
				return target->parent;
			}
		}
	}
};

//int main() {
//	TreeNode* root = new TreeNode(1);
//	TreeNode* node1 = new TreeNode(2);
//	TreeNode* node2 = new TreeNode(3);
//	TreeNode* node3 = new TreeNode(4);
//	TreeNode* node4 = new TreeNode(5);
//	TreeNode* node5 = new TreeNode(6);
//	TreeNode* node6 = new TreeNode(7);
//	TreeNode* node7 = new TreeNode(8);
//	TreeNode* node8 = new TreeNode(9);
//
//	root->left = node1;
//	root->right = node2;
//
//	node1->left = node3;
//	node1->right = node4;
//	node1->parent = root;
//
//	node2->left = node5;
//	node2->right = node6;
//	node2->parent = root;
//
//	node3->parent = node1;
//
//	node4->left = node7;
//	node4->right = node8;
//	node4->parent = node1;
//
//	node5->parent = node2;
//	node6->parent = node2;
//
//	node7->parent = node4;
//	node8->parent = node4;
//
//	TreeNode* nextTreeNode = Solution().nextNode(root, node6);
//	cout << nextTreeNode->val << endl;
//	return 0;
//}