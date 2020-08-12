#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int len = nums.size();
        vector<vector<int>> ret;
        for (int i = 0; i < len-2; i++) {
            if (nums[i] > 0)    return ret;
            if (i>0 && nums[i] == nums[i - 1])    continue;   //保证左端不重复

            int left = i + 1;
            int right = len - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    vector<int> tmp{ nums[i], nums[left], nums[right] };
                    ret.push_back(tmp);

                    while (left < right && nums[left + 1] == nums[left]) //保证中间数不重复
                        left++;
                    while (left < right && nums[right - 1] == nums[right]) //保证右端不重复
                        right--;
                    left++;
                    right--;
                    continue;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else
                {
                    right--;
                }
            }
        }

        return ret;
    }
};

//int main() {
//    vector<int> nums{-1, 0, 1, 2, -1, -4};
//
//    vector<vector<int>> res = Solution().threeSum(nums);
//    for (int i = 0; i < res.size(); i++) {
//        for (int j = 0; j < res[i].size(); j++) {
//            cout << res[i][j] << " ";
//        }
//        cout << endl;
//    }
//}