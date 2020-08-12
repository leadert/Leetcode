#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int calSum(int row, int column) {
        int sum = 0;
        while (row) {
            sum += row % 10;
            row = row / 10;
        }
        while (column) {
            sum += column % 10;
            column = column / 10;
        }
        return sum;
    }

    void dfs(int i, int j, int m, int n, int k, vector<vector<int>>& flag) {
        if (i < 0 || i >= m || j < 0 || j >= n)  return;
        if (calSum(i, j) <= k && i < m && j < n) {
            flag[i][j] = 1;
            if ((i + 1) < m && flag[i + 1][j] == false)   dfs(i + 1, j, m, n, k, flag);
            if ((j + 1) < n && flag[i][j + 1] == false)   dfs(i, j + 1, m, n, k, flag);
        }
        else    return;
    }

    int movingCount(int m, int n, int k) {
        vector<vector<int>> flag(m, vector<int>(n));
        dfs(0, 0, m, n, k, flag);
        int count = 0;
        for (auto x : flag) {
            for (auto y : x) {
                if (y == 1)  count += 1;
            }
        }
        return count;
    }
};