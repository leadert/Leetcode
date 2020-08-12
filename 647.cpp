#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;

        int len = s.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j <= len; j++) {
                string tmp = s.substr(i, j - i);
                int left = 0;
                int right = tmp.size() - 1;
                while (left <= right) {
                    if (tmp[left] != tmp[right]) {
                        break;
                    }

                    else if (left == right || left == right - 1) {
                        count += 1;
                        break;
                    }
                    left++;
                    right--;
                }
            }
        }

        return count;
    }
};