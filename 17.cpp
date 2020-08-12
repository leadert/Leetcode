#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) return res;

        unordered_map<char, string> phone;
        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pqrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";

        for (int i = 0; i < phone[digits[0]].size(); i++) {
            string s;
            s.push_back(phone[digits[0]][i]);
            res.push_back(s);
        }

        for (int i = 1; i < digits.size(); i++) {
            string tmpStr = phone[digits[i]];
            vector<string> tmpVec;
            for (int j = 0; j < tmpStr.size(); j++) {
                for (int k = 0; k < res.size(); k++) {
                    tmpVec.push_back(res[k] + tmpStr[j]);
                }
            }
            res = tmpVec;
        }
        return res;
    }
};


//int main() {
//    string phoneNumber = "23";
//    vector<string> res = Solution().letterCombinations(phoneNumber);
//    for (int i = 0; i < res.size(); i++) {
//        cout << res[i] << ",";
//    }
//    cout << endl;
//}