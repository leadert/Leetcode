#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortAraay(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        int left1 = left, right1 = mid - 1;
        root->left = sortAraay(nums, left1, right1);
        int left2 = mid + 1, right2 = right;
        root->right = sortAraay(nums, left2, right2);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        TreeNode* ret = sortAraay(nums, 0, len - 1);
        return ret;
    }
};