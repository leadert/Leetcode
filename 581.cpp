#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();

        //������Ѱ��ͻȻ��С��Ԫ�أ������ҵ���������СֵԪ��
        int minValue = INT_MAX;
        for (int i = 1; i < len; i++) {
            if (nums[i] < nums[i - 1]) {
                minValue = min(minValue, nums[i]);
            }
        }

        //���ҵ���Ѱ��ͻȻ�����Ԫ�أ������ҵ����������ֵԪ��
        int maxValue = INT_MIN;
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                maxValue = max(maxValue, nums[i]);
            }
        }

        if (minValue == INT_MAX)
            return 0;

        //�ҵ���СԪ����ԭ�����е�λ��
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