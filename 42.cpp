#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        vector<int> left(n);
        vector<int> right(n);

        left[0] = 0;
        right[n - 1] = 0;
        int count = 0;
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i-1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i+1]);
        }
        for (int i = 0; i < n; i++) {
            int temp = min(left[i], right[i]);
            count += max(0, temp - height[i]);
        }
        return count;
    }
};


//int main() {
//    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
//    int ret = Solution().trap(height);
//    cout << ret;
//}