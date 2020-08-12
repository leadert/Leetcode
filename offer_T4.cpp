// 不修改数组找出重复的数字
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool findNumberInArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())  return false;

        int rows = matrix.size();
        int columns = matrix[0].size();

        int i = 0, j = columns - 1;
        while (i < rows && j >= 0) {
            if (matrix[i][j] == target)  return true;
            else if (matrix[i][j] > target)
                j--;
            else
                i++;
        }

        return false;
    }
};

//int main() {
//	vector<vector<int>> nums;
//	nums.push_back({1,2,8});
//	nums.push_back({ 2,4,9 });
//	nums.push_back({ 4,7,10 });
//
//	bool flag = Solution().findNumInArray(nums,12);
//	if (flag)	cout << "True" << endl;
//	else cout << "False" << endl;
//	return 0;
//}