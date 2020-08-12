#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> getMatrixNum(vector<vector<int>>& matrix, int leftRow, int leftColumn, int rightRow, int rightColumn) {
		vector<int> ans;
		if (leftRow == rightRow && leftColumn == rightColumn)	ans.push_back(matrix[leftRow][leftColumn]);

		else if (leftRow == rightRow) {
			for (int i = leftColumn; i <= rightColumn; i++) {
				ans.push_back(matrix[leftRow][i]);
			}
		}
		
		else if (leftColumn == rightColumn) {
			for (int i = leftRow; i <= rightRow; i++) {
				ans.push_back(matrix[i][rightColumn]);
			}
		}

		else {
			for (int i = leftColumn; i < rightColumn; i++) {
				ans.push_back(matrix[leftRow][i]);
			}

			for (int i = leftRow; i < rightRow; i++) {
				ans.push_back(matrix[i][rightColumn]);
			}

			for (int i = rightColumn; i > leftColumn; i--) {
				ans.push_back(matrix[rightRow][i]);
			}

			for (int i = rightRow; i > leftRow; i--) {
				ans.push_back(matrix[i][leftColumn]);
			}
		}

		return ans;
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())	return {};

		vector<int> result;
		int leftRow = 0, leftColumn = 0;
		int rightRow = matrix.size() - 1, rightColumn = matrix[0].size() - 1;

		while (leftRow <= rightRow && leftColumn <= rightColumn) {
			vector<int>tmpVec =  getMatrixNum(matrix, leftRow++, leftColumn++, rightRow--, rightColumn--);
			for (auto number : tmpVec) {
				result.push_back(number);
			}
		}

		return result;
	}
};


//int main() {
//	vector<vector<int>> matrix;
//	matrix.push_back({ 6,9,7 });
//
//	vector<int> result = Solution().spiralOrder(matrix);
//	for (auto number : result)
//		cout << number << " ";
//	return 0;
//}