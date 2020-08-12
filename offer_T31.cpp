#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> numStack;
        int j = 0;
        for (int i = 0; i < pushed.size(); i++) {
            numStack.push(pushed[i]);
            while (!numStack.empty() && numStack.top() == popped[j]) {
                numStack.pop();
                j++;
            }
        }

        return numStack.empty();
    }
};