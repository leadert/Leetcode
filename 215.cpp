//数组中的第k个最大元素
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    /*方法一：C++自带的优先队列*/
    /*int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> kSmallHeap;
        for (int i = 0; i < k; i++) {
            kSmallHeap.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            kSmallHeap.push(nums[i]);
            kSmallHeap.pop();
        }

        int ret = kSmallHeap.top();
        return ret;
    }*/
    int findKthLargest(vector<int>& nums, int k) {
        
    }
};

//int main() {
//    vector<int> nums{ 3,2,3,1,2,4,5,5,6 };
//    int ret = Solution().findKthLargest(nums, 4);
//    cout << ret;
//
//    return 0;
//}