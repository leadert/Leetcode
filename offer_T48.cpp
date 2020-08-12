#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())   return 0;
        if (s.size() == 1)   return 1;

        int maxSubLength = 0;
        int nLength = s.size();
        int left = 0, right = 0;
        unordered_map<char, int> chMap;

        while (right < nLength) {
            char c = s[right];
            chMap[c]++;
            right++;

            while (chMap[c] > 1) {
                char d = s[left];
                chMap[d]--;
                left++;
            }

            maxSubLength = max(maxSubLength, right - left);
        }

        return maxSubLength;
    }
};