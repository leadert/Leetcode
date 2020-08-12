#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        for (int i = 1; i < rows; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int j = 1; j < columns; j++) {
            grid[0][j] += grid[0][j - 1];
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
            }
        }

        return grid[rows - 1][columns - 1];
    }
};