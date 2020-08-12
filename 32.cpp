#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty())  return 0;

        int maxLength = 0;
        vector<int> parenthesesStack{ -1 };
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                parenthesesStack.push_back(i);
            }

            else if(s[i] == ')'){
                parenthesesStack.pop_back();
                if (parenthesesStack.empty()) {
                    parenthesesStack.push_back(i);
                }
                else
                {
                    maxLength = max(maxLength, i - parenthesesStack.back());
                }
            }
        }
        return maxLength;
    }
};

//int main() {
//    string s = "(()()";
//    int ret = Solution().longestValidParentheses(s);
//    cout << ret << endl;
//    return 0;
//}