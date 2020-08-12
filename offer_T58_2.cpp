#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if (!s.empty()) {
            int nLength = s.size();
            if (nLength > 0 && n > 0 && n < nLength) {
                reverse(s.begin(), s.begin() + n);
                reverse(s.begin() + n, s.end());
                reverse(s.begin(), s.end());
            }
        }

        return s;
    }
};