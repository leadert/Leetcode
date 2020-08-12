#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Î´½â¾ö
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (nums[mid] == target)   return mid;
            if (left == right)   break;
            else if (nums[left] < nums[right]) {
                if (nums[mid] > target) right = mid - 1;
                else left = mid + 1;
                continue;
            }
            else if(nums[left] > nums[right]){
                if (nums[mid] < nums[right]) {
                    if (nums[mid] > target)    right = mid - 1;
                    else {
                        if (target > nums[right])  right = mid - 1;
                        else left = mid + 1;
                    }
                }
                else if (nums[mid] > nums[right]) {
                    if (nums[mid] > target) {
                        if (target <= nums[right]) left = mid + 1;
                        else right = mid - 1;
                    }
                    else left = mid + 1;
                }
            }
        }
        return -1;
    }
};

//int main() {
//    vector<int> nums = { 4,5,6,7,0,1,2 };
//    int target = 8;
//    int ret = Solution().search(nums, target);
//    cout << ret;
//    return 0;
//}