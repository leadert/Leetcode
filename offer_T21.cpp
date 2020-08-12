#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty())    return {};

        int nLength = nums.size();
        int left = 0, right = nLength - 1;
        while (left < right) {
            if ((nums[left] & 0x1) == 0 && (nums[right] & 0x1))
                swap(nums[left++], nums[right--]);
            if (nums[left] & 0x1)  left++;
            if ((nums[right] & 0x1) == 0) right--;
        }

        return nums;
    }
};

//int main() {
//    vector<int> nums{ 2, 16, 3, 5, 13, 1, 16, 1, 12, 18, 11, 8, 11, 11, 5, 1 };
//    vector<int> ans = Solution().exchange(nums);
//    for (auto number : ans)
//        cout << number << " ";
//    return 0;
//}