//����ϰ

//����ǰ����������й���������

//�ݹ����⣬myBulidTree()���� ����ǰ�������ҵ���ǰ���ڵ㣬�����������м���������������
//�ݹ������������ǰ�����С��������У������ظ��ڵ�

//���ڵ�leftָ��ָ��myBuildTree(������)��rightָ��ָ��myBuildTree(������)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};


class Solution {
private:
	unordered_map<int, int> inorderElementIndex;
public:
	TreeNode* buildingMyTree(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
		if (preLeft > preRight)	return nullptr;
		TreeNode* root = new TreeNode(preorder[preLeft]);
		int inorderIndex = inorderElementIndex[preorder[preLeft]];
		int sizeLeftTree = inorderIndex - inLeft;
		root->left = buildingMyTree(preorder, inorder, preLeft + 1, preLeft + sizeLeftTree, inLeft, inorderIndex - 1);
		root->right = buildingMyTree(preorder, inorder, preLeft + sizeLeftTree + 1, preRight, inorderIndex + 1, inRight);
		return root;
	}

	TreeNode* bulidTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		for (int i = 0; i < n; i++) {
			inorderElementIndex[inorder[i]] = i;
		}

		return buildingMyTree(preorder, inorder, 0, n - 1, 0, n - 1);
	}
};