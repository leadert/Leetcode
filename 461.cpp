#include<iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x ^ y;
        if (t == 0)    return 0;

        int count = 0;
        while (t) {
            //&运算符，只有为1&1=1
            count += (t & 1);
            t = t >> 1;
        }

        return count;
    }
};