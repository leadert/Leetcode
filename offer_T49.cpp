#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0)    return -1;
        vector<int> uglyVec(n);
        uglyVec[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; i++) {
            uglyVec[i] = min(uglyVec[a] * 2, uglyVec[b] * 3);
            uglyVec[i] = min(uglyVec[i], uglyVec[c] * 5);
            if (uglyVec[i] == uglyVec[a] * 2)    a++;
            if (uglyVec[i] == uglyVec[b] * 3)    b++;
            if (uglyVec[i] == uglyVec[c] * 5)    c++;
        }

        return uglyVec[n - 1];
    }
};