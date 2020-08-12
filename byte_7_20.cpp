#include <iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    string getSToString(string S) {
        if (S.empty())   return {};
        stack<int> ret;
        int len = S.size();
        for (int i = len - 1; i >= 0; i--) {
            if (S[i] > '0' && S[i] <= '9') {
                string tmp;
                ret.pop();    //删除‘[’
                while (ret.top() != ']') {
                    tmp += ret.top();
                    ret.pop();
                }
                ret.pop();   //"删除‘]’"
                for (int k = 0; k < (int)S[i]-48; k++) {         //刚才的bug：1.k写成了上面的i，混用；2.S[i]char类型，不是int类型
                    for (int j = tmp.size() - 1; j >= 0; j--) {
                        ret.push(tmp[j]);
                    }
                }
            }
            else {
                ret.push(S[i]);
            }
        }
        string ans;
        while (!ret.empty()) {
            if (ret.top() >= 'a' && ret.top() <= 'z') {
                ans += ret.top();
                ret.pop();
            }
            else {
                return {};
            }
        }
        return ans;
    }
};

int main() {
    string S = "2[abc]3[cd]ef";
    string ans = Solution().getSToString(S);
    cout << ans << endl;
    return 0;
}