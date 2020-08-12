#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        bool first_match = (p[0] == s[0] || p[0] == '.');
        if (p.size() >= 2 && p[1] == '*') {
            if (s.empty())
                return isMatch(s, p.substr(2));
            else
                return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        }
        else {
            if (s.empty())
                return false;
            else
                return isMatch(s.substr(1), p.substr(1)) && first_match;
        }
    }
};


//int main() {
//    /*string s, p;
//    cin >> s;
//    cin >> p;*/
//    bool flag = Solution().isMatch(" ", ".*");
//    if (flag) cout << "true";
//    else cout << "false";
//}