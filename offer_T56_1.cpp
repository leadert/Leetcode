#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int bitSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            bitSum = bitSum ^ nums[i];
        }

        int calBit = 1;
        while ((calBit & bitSum) == 0) {
            calBit <<= 1;
        }

        int a = 0, b = 0;
        for (auto n : nums) {
            if (n & calBit) {
                a = a ^ n;
            }
            else {
                b = b ^ n;
            }
        }

        return vector<int>{a, b};
    }
};