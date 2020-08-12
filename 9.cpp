#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		string str = to_string(x);
		string reverseStr = str;
		reverse(reverseStr.begin(), reverseStr.end());
		if (reverseStr == str) return true;
		else return false;
	}
};

//int main() {
//	int x;
//	cin >> x;
//
//	bool flag = Solution().isPalindrome(x);
//	if (flag) cout << "true";
//	else {
//		cout << "false";
//	}
//}