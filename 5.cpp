#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        if (s.size() == 1)
            return s;

        string res = "";
        int sSize = int(s.size());
        vector<bool> tmpVec(sSize, false);
        vector<vector<bool>> dp(sSize, tmpVec);

        int start = 0, end = 0, maxLen = 0;
        for (int len = 1; len <= sSize; len++) {
            for (int i = 0; i < sSize; i++) {
                int j = i + len - 1;
                if (j >= sSize) {
                    break;
                }
                dp[i][j] = (len == 1 || len == 2 || dp[i + 1][j - 1]) && s[i] == s[j];
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }
        res = s.substr(start, end - start + 1);
        return res;
    }
};


//int main() {
//    string s;
//    cin >> s;
//
//    Solution a;
//    string res = a.longestPalindrome(s);
//    cout << res << endl;
//}