#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();

        int maxLength = nums[0];
        for (int i = 1; i < len; i++) {
            if (i <= maxLength) {
                maxLength = max(maxLength, nums[i] + i);
                if (maxLength >= len - 1) {
                    return true;
                }
            }
        }
        return maxLength >= len - 1;
    }
};