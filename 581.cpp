#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();

        //从左到右寻找突然减小的元素，并且找到这样的最小值元素
        int minValue = INT_MAX;
        for (int i = 1; i < len; i++) {
            if (nums[i] < nums[i - 1]) {
                minValue = min(minValue, nums[i]);
            }
        }

        //从右到左寻找突然增大的元素，并且找到这样的最大值元素
        int maxValue = INT_MIN;
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                maxValue = max(maxValue, nums[i]);
            }
        }

        if (minValue == INT_MAX)
            return 0;

        //找到最小元素在原数组中的位置
        int leftIndex;
        for (int i = 0; i < len; i++) {
            if (minValue < nums[i]) {
                leftIndex = i;
                break;
            }
        }

        int rightIndex;
        for (int i = len - 1; i >= 0; i--) {
            if (maxValue > nums[i]) {
                rightIndex = i;
                break;
            }
        }

        int res = rightIndex - leftIndex + 1;
        return res;
    }
};