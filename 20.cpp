#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pair;
        pair[')'] = '(';
        pair['}'] = '{';
        pair[']'] = '[';

        vector<char> stack;
        stack.push_back('f');
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push_back(s[i]);
            }
            else {
                char r = stack.back();
                if (r == pair[s[i]]) {
                    stack.pop_back();
                }

                else return false;
            }
        }
        if (stack.back() == 'f') return true;
        else return false;
    }
};


//int main() {
//    string str;
//    cin >> str;
//
//    bool ret = Solution().isValid(str);
//    if (ret) cout << "true";
//    else cout << "false";
//}