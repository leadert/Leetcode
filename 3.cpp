#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char, int> window;
        int left = 0, right = 0;
        while (right < s.size()) {
            char c = s[right];
            window[c]++;
            right++;

            while (window[c] > 1) {
                char d = s[left];
                window[d]--;
                left++;
            }

            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }
};


//int main() {
//    string s;
//    cin >> s;
//
//    Solution a;
//    int max_length = a.lengthOfLongestSubstring(s);
//    cout << max_length << endl;
//
//    return 0;
//}
