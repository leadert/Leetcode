#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	bool matchWord(vector<vector<char>>& nums, vector<vector<bool>> flag, string word, int row, int column) {
		if (word.empty())	return true;
		if (row < 0 || row >= nums.size() || column < 0 || column >= nums[0].size())
			return false;
		if (nums[row][column] == word[0] && flag[row][column] == false) {
			flag[row][column] = true;
			return matchWord(nums, flag, word.substr(1), row + 1, column) || matchWord(nums, flag, word.substr(1), row - 1, column)
				|| matchWord(nums, flag, word.substr(1), row, column + 1) || matchWord(nums, flag, word.substr(1), row, column - 1);
		}
		else return false;
	}

	bool pathInMatrix(vector<vector<char>>& nums, string word) {
		if (nums.empty())	return false;
		int row = nums.size();
		int column = nums[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (nums[i][j] == word[0]) {
					vector<vector<bool>> flag(row, vector<bool>(column));
					bool tag = matchWord(nums, flag, word, i, j);
					if (tag == true)	return true;
				}
			}
		}
		return false;
	}
};


//int main() {
//	vector<vector<char>> matrix(3, vector<char>(4));
//	matrix = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'} };
//
//	bool ansFlag = Solution().pathInMatrix(matrix, "ABCESEEEFS");
//	cout << ansFlag << " ";
//	return 0;
//}