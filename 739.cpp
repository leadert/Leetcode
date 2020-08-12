//Ѱ��һ��Ԫ�غ����һ���������Ԫ�أ�����ջ��˼��

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) return {};
        int len = T.size();
        vector<int> res(len, 0);

        stack<int> tmpStack;
        tmpStack.push(0);
        for (int i = 1; i < len; i++) {
            //��ǰԪ��С�ڵ���ǰһ��Ԫ�أ�ջ��Ԫ�أ�
            if (T[i] <= T[tmpStack.top()]) {
                tmpStack.push(i);
            }

            //��ǰԪ�ش���ǰһ��Ԫ��
            else {
                while (!tmpStack.empty() && T[i] > T[tmpStack.top()]) {
                    res[tmpStack.top()] = i - tmpStack.top();
                    tmpStack.pop();
                }
                tmpStack.push(i);
            }
        }

        while (!tmpStack.empty()) {
            res[tmpStack.top()] = 0;
            tmpStack.pop();
        }

        return res;
    }
};