#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = { -1,-1 };
        if (nums.empty()) return ret;

        ret.pop_back();
        ret.pop_back();
        int left = 0;
        int right = nums.size() - 1;

        int first = -1;
        int last = -1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (target == nums[mid]) {
                first = mid;
                last = mid;

                int i = 0;
                for (i = (mid - 1); i >= left; i--) {
                    if (target != nums[i]) {
                        first = i + 1;
                        break;
                    }
                }
                if (i <= left && nums[left] == target) first = left;

                for (i = (mid + 1); i <= right; i++) {
                    if (target != nums[i]) {
                        last = i - 1;
                        break;
                    }
                }
                if (i >= right && nums[right] == target) last = right;
                ret.push_back(first);
                ret.push_back(last);
                return ret;
            }

            else if (target < nums[mid]) right = mid - 1;
            else if (target > nums[mid]) left = mid + 1;
        }

        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    }
};


//int main() {
//    vector<int> nums = { 5,7,7,8,8,10 };
//    vector<int> ret = Solution().searchRange(nums, 8);
//    for (int i = 0; i < ret.size(); i++) {
//        cout << ret[i] << " ";
//    }
//}