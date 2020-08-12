//找打字符串中的所有字母异位词
//滑动窗口思想，p字符串长度固定

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
	vector<int> findAndgrams(string s, string p) {
		unordered_map<char, int> need, window;
		for (auto x : p) {
			need[x]++;
		}

		vector<int> res;
		int left = 0, right = 0;
		int valid = 0;

		while (right < s.size()) {
			char c = s[right];
			right++;

			//窗口内数据更新
			if (need.count(c)) {
				window[c]++;
				if (window[c] == need[c])
					valid++;
			}

			//判断左侧是否需要收缩
			while (right - left >= p.size()) {
				//窗口符合条件时，起始索引加入res
				if (valid == need.size())
					res.push_back(left);
				char d = s[left];
				left++;
				//窗口内数据更新
				if (need.count(d)) {
					if (window[d] == need[d])
						valid--;
					window[d]--;
				}
			}
		}
		return res;
	}
};


//int main() {
//	string s = "cbaebabacd";
//	string p = "abc";
//	vector<int> res = Solution().findAndgrams(s, p);
//	for (int i = 0; i < res.size(); i++) {
//		cout << res[i] << " ";
//	}
//}