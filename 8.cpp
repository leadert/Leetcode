#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		string res;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '\t' && str.empty()) continue;
			else if ((str[i] == '-' || str[i] == '+') && res.empty()) {
				res += str[i];
			}
			else if ('0' <= str[i] && str[i] <= '9') {
				res += str[i];
			}
			else if (str[i] < '0' || str[i] > '9') {
				break;
			}
		}

		long long int num;
		if (res.empty()) return 0;
		else {
			num = stoll(res);
		}
		
		if (pow(-2, 31) <= num && num <= (pow(2, 31) - 1)) return int(num);
		else {
			if (num < pow(-2, 31)) return INT32_MIN;
			else return INT32_MAX;
		}
		return int(num);
	}
};


//int main() {
//	string s;
//	cin >> s;
//
//	Solution a;
//	int res = a.myAtoi(s);
//	string out = to_string(res);
//	cout << out << endl;
//}