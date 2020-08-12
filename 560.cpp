#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();

        int count = 0;
        int sum;
        for (int i = 0; i < len; i++) {
            sum = 0;
            for (int j = i; j < len; j++) {
                sum += nums[j];
                if (sum == k)  count++;
            }
        }
        return count;
    }
};