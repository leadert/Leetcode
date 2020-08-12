#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
	//long型整数，防止溢出
	int reverse(int x) {
		int xNum = abs(x);
		int flag = (xNum == x ? 0 : 1);

		long int res = 0;
		while (xNum != 0) {
			int lastNum = xNum % 10;
			xNum = xNum / 10;

			res = res * 10 + lastNum;
		}
		res = (flag == 1 ? -res : res);
		res = (((pow(-2, 31) <= res && res <= pow(2, 31) - 1)) ? res : 0);
		return res;
	}
};


//int main() {
//	int x;
//	cin >> x;
//	
//	Solution a;
//	int res = a.reverse(x);
//	cout << res << endl;
//}