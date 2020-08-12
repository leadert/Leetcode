//�ж�string�Ƿ���Ա����Ϊ����wordDict�еĵ���
//��̬�滮��dp[i]�ܷ񱻲�֣��ֽ�Ϊ������

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