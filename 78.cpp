#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res = { {} };
        for (int i = 0; i < len; i++) {
            vector<vector<int>> tmp = res;
            for (vector<int> x : tmp) {
                x.push_back(nums[i]);
                res.push_back(x);
            }
        }
        
        return res;
    }
};