#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> priority;
		priority['I'] = 1;
		priority['V'] = 5;
		priority['X'] = 10;
		priority['L'] = 50;
		priority['C'] = 100;
		priority['D'] = 500;
		priority['M'] = 1000;

		int num = 0;
		int i = 0;
		while (i < s.size()) {
			if (priority[s[i]] >= priority[s[i + 1]]) {
				num += priority[s[i]];
			}

			else {
				num -= priority[s[i]];
			}
			i++;
		}
		return num;
	}
};


//int main() {
//	string str;
//	cin >> str;
//
//	int res = Solution().romanToInt(str);
//	cout << res;
//}