#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] = tmp;
            }
        }
    }
};


//int main() {
//    vector<vector<int>> a = { {1,2,3},{4,5,6},{7,8,9} };
//    Solution().rotate(a);
//    for (auto x : a) {
//        for (auto num : x) {
//            cout << num << " ";
//        }
//        cout << endl;
//    }
//}