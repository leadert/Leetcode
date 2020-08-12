#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int translateNum(int num) {
        if (num == 0)   return 1;

        int nLength = 0;
        int cpNum = num;
        while (cpNum) {
            cpNum = cpNum / 10;
            nLength++;
        }
        if (nLength == 1)    return 1;
        string Numstr = to_string(num);
        vector<int> dp(nLength, 0);
        dp[0] = 1;
        if (Numstr[0] == '1' || (Numstr[0] == '2' && (Numstr[1] >= '0' && Numstr[1] <= '5'))) {
            dp[1] = 2;
        }
        else
            dp[1] = 1;

        for (int i = 2; i < nLength; i++) {
            dp[i] = dp[i - 1];
            auto tmpStr = Numstr.substr(i - 1, 2);
            if ("10" <= tmpStr && tmpStr <= "25")  dp[i] += dp[i - 2];
        }

        return dp[nLength - 1];
    }
};

//int main() {
//    int n = 12258;
//    cout << Solution().translateNum(n) << endl;
//    return 0;
//}