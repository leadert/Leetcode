#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        if (s.empty())   return ' ';

        int nLength = s.size();
        unordered_map<char, int>   chMap{ 26 };
        for (int i = 0; i < nLength; i++) {
            char c = s[i];
            if (chMap.count(c) == 0)    chMap[c] = 1;
            else    chMap[c]++;
        }

        for (int i = 0; i < nLength; i++) {
            if (chMap[s[i]] == 1)  return s[i];
        }

        return ' ';
    }
};