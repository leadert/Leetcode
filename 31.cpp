#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() != 0) {
            int flag = -1;
            for (int i = nums.size() - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    for (int j = nums.size() - 1; j > i; j--) {
                        if (nums[j] > nums[i]) {
                            int temp = nums[j];
                            nums[j] = nums[i];
                            nums[i] = temp;
                            break;
                        }
                    }
                    int left = i + 1; 
                    reverse(nums.begin() + left, nums.end());
                    flag = 1;
                    break;
                }
            }
            if (flag == -1) {
                reverse(nums.begin(), nums.end());
            }
        }
    }
};

//int main() {
//    vector<int> nums = { 1,4,7,6,5,3 };
//    Solution().nextPermutation(nums);
//    for (int i : nums) {
//        cout << i << " ";
//    }
//}