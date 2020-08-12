#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;

        if (n == 0) return res;

        sort(nums.begin(), nums.begin() + n);
        for (int i = 0; i < n-3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i+1; j < n-2; j++) {
                if (j > (i + 1) && nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    if (nums[i] + nums[j] + nums[left] + nums[right] == target) {
                        vector<int> tmpVec;
                        tmpVec.push_back(nums[i]);
                        tmpVec.push_back(nums[j]);
                        tmpVec.push_back(nums[left]);
                        tmpVec.push_back(nums[right]);
                        res.push_back(tmpVec);
                        while (left < right && nums[left + 1] == nums[left])
                            left++;
                        while (left < right && nums[right - 1] == nums[right])
                            right--;
                        left++; right--;
                    }
                    else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return res;
    }
};


//int main() {
//    vector<int> nums;
//    nums.push_back(-3);
//    nums.push_back(-2);
//    nums.push_back(-1);
//    nums.push_back(0);
//    nums.push_back(0);
//    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(3);
//
//    vector<vector<int>> res = Solution().fourSum(nums, 0);
//    for (int i = 0; i < res.size(); i++) {
//        for (int j = 0; j < 4; j++) {
//            cout << res[i][j] << " ";
//        }
//        cout << endl;
//    }
//}