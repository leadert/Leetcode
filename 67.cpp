#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string ans;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int n = max(a.size(), b.size());
		int carry = 0;
		for (int i = 0; i < n; i++) {
			carry += i < a.size() ? (a.at(i) == '1') : 0;
			carry += i < b.size() ? (b.at(i) == '1') : 0;
			ans.push_back((carry % 2) ? '1' : '0');
			carry /= 2;
		}

		if (carry)	ans.push_back('1');
		reverse(ans.begin(), ans.end());

		return ans;
	}
};

//int main() {
//	string a = "11";
//	string b = "1";
//	string ans = Solution().addBinary(a, b);
//	cout << ans;
//	return 0;
//}