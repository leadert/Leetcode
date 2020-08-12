//寻找一个元素后面第一个比它大的元素，利用栈的思想

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
            //当前元素小于等于前一个元素（栈顶元素）
            if (T[i] <= T[tmpStack.top()]) {
                tmpStack.push(i);
            }

            //当前元素大于前一个元素
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