#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return NULL;

        int minDis = abs(nums[0]+nums[1]+nums[2]-target);
        int threeSum = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.begin() + nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int tmpNum = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (abs(tmpNum + nums[left] + nums[right]-target)<minDis) {
                    minDis = abs(tmpNum + nums[left] + nums[right]-target);
                    threeSum = tmpNum + nums[left] + nums[right];
                }
                if (tmpNum + nums[left] + nums[right] - target <= 0 ) left++;
                else right--;
            }
        }
        return threeSum;
    }
};


//int main() {
//    vector<int> nums;
//    nums.push_back(1);
//    nums.push_back(1);
//    nums.push_back(1);
//    nums.push_back(0);
//
//    int res = Solution().threeSumClosest(nums,100);
//    cout << res;
//}