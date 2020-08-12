#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    set<string> ans;
    void  dfs(string permutStr, string plusStr) {
        for (int i = 0; i < plusStr.size(); i++) {
            string tmpStr = permutStr + plusStr[i];
            string remainStr = plusStr;
            remainStr = remainStr.erase(i, 1);
            if (remainStr.empty()) {
                ans.insert(tmpStr);
            }
            dfs(tmpStr, remainStr);
        }
    }

    vector<string> permutation(string s) {
        if (s.empty())   return {};
        if (s.size() == 1)   return { s };

        for (int i = 0; i < s.size(); i++) {
            string tmpStr(1, s[i]);
            string remainStr(s);
            remainStr = remainStr.erase(i, 1);
            dfs(tmpStr, remainStr);
        }

        return vector<string>(ans.begin(), ans.end());
    }
};


//int main() {
//    string s = "aab";
//    vector<string> result = Solution().permutation(s);
//    for (auto x : result) {
//        cout << x << endl;
//    }
//    return 0;
//}