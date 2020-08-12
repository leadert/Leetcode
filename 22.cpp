#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> ret(n+1);
        
        ret[0].push_back("");
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (string& str1 : ret[j]) {
                    for (string& str2 : ret[i - j - 1]) {
                        ret[i].push_back("(" + str1 + ")" + str2);
                    }
                }
            }
        }
        return ret[n];
    }
};

//int main() {
//    int n = 3;
//    vector<string> ret = Solution().generateParenthesis(n);
//    for (string& str : ret) {
//        cout << str << endl;
//    }
//}