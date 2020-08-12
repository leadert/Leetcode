#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLength = INT32_MAX;
        string res = "";

        if (strs.size() == 0) return res;         // 不能忽略对strs为空时候的判断

        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].empty()) return res;
            else
                minLength = min(minLength, int(strs[i].size()));
        }

        for (int j = 0; j < minLength; j++) {
            int flag = 1;
            char r = strs[0][j];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][j] != r) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) res += r;
            else return res;
        }
        return res;
    }
};

//int main() {
//    vector<string> str;
//    str.push_back("flower");
//    str.push_back("flow");
//    str.push_back("flight");
//
//    string res = Solution().longestCommonPrefix(str);
//    cout << res;
//}