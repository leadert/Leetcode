#include<iostream>
using namespace std;


class Solution {
public:
    // int hammingWeight(uint32_t n) {
    //     int count = 0;
    //     uint32_t flag = 1;
    //     while(flag){
    //         if(n&flag)  count++;
    //         flag = flag << 1;
    //     }
    //     return count;
    // }
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count++;
            n = (n - 1) & n;
        }
        return count;
    }
};