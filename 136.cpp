//�ҳ�������ֻ����һ�ε����֣�����ʱ�䣬�޶���ռ�
//˼�뾫�����õ�̫�����ˣ���ͬԪ���������㣬��ͬԪ�����

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0];
        for (int i = 1; i < len; i++) {
            res ^= nums[i];
        }
        return res;
    }
};