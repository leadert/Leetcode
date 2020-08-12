#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
	string minWindow(string s, string t) {
		unordered_map<char, int> need, window;
		for (auto x : t)
			need[x]++;

		string res;
		int minLength = INT_MAX;
		int left = 0, right = 0;
		int valid = 0;
		while (right < s.size()) {
			char c = s[right];
			right++;

			if (need.count(c)) {
				window[c]++;
				if (window[c] == need[c])
					valid++;
			}

			while (valid >= need.size()) {
				if (valid == need.size() && (right-left)<minLength) {
					minLength = right - left;
					res = s.substr(left, right - left);
				}

				char d = s[left];
				left++;

				if (need.count(d)) {
					if (window[d] == need[d]) {
						valid--;
					}
					window[d]--;
				}
			}
		}

		return res;
	}
};