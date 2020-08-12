#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();

        vector<int> colorCount(3, 0);
        for (int i = 0; i < len; i++) {
            colorCount[nums[i]]++;
        }

        for (int i = 0; i < colorCount[0]; i++) {
            nums[i] = 0;
        }

        for (int i = colorCount[0]; i < colorCount[0] + colorCount[1]; i++) {
            nums[i] = 1;
        }

        for (int i = colorCount[0] + colorCount[1]; i < len; i++) {
            nums[i] = 2;
        }
    }
};