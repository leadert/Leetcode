#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9)    return 9;

        n -= 9;
        long long count = 90, digit = 2;
        while (n > count * digit) {
            n -= count * digit;
            count *= 10;
            digit += 1;
        }

        long long targetNum = pow(10, digit-1) + n/digit;
        if (targetNum % digit == 0) {
            targetNum--;
            return targetNum % 10;
        }
        else
        {
            for (int i = 0; i < (digit - n % digit); i++) {
                targetNum /= 10;
            }

            return targetNum % 10;
        }
    }
};