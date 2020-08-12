#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSubSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + max(nums[i - 1], 0);
        }
       
        int maxValue = INT32_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxValue = max(nums[i], maxValue);
        }

        return maxValue;
    }
};

//int main() {
//    vector<int> ques = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
//    int res = Solution().maxSubArray(ques);
//    cout << res;
//}