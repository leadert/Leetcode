#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            if (dict.find(target - nums[i]) != dict.end())
                return { dict[target - nums[i]], i };
            dict[nums[i]] = i;
        }
        return {};
    }
};


//int main() {
//    Solution a;
//    vector<int> nums;
//    nums.push_back(2);
//    nums.push_back(7);
//    nums.push_back(12);
//    nums.push_back(15);
//
//    vector<int> result = a.twoSum(nums, 9);
//    for (int i = 0; i < result.size(); i++) {
//        cout << result[i] << " ";
//    }
//    cout << endl;
//	return 0;
//}