#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int maxGiftValue(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		int columns = matrix[0].size();
		vector<vector<int>> giftValue(rows, vector<int>(columns));
		giftValue[0][0] = matrix[0][0];
		for (int i = 1; i < columns; i++) {
			giftValue[0][i] = giftValue[0][i - 1] + matrix[0][i];
		}

		for (int i = 1; i < rows; i++) {
			giftValue[i][0] += giftValue[i - 1][0] + matrix[i][0];
		}

		for (int i = 1; i < rows; i++) {
			for (int j = 1; j < columns; j++) {
				giftValue[i][j] = max(giftValue[i - 1][j], giftValue[i][j - 1]) + matrix[i][j];
			}
		}

		return giftValue[rows - 1][columns - 1];
	}
};