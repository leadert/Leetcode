//找出数组中只出现一次的数字，线性时间，无额外空间
//思想精妙，异或用的太神奇了；相同元素异或等于零，不同元素异或

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0];
        for (int i = 1; i < len; i++) {
            res ^= nums[i];
        }
        return res;
    }
};