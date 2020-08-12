//判断string是否可以被拆分为若干wordDict中的单词
//动态规划，dp[i]能否被拆分，分解为子问题

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.find(s.substr(i, j - i)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};