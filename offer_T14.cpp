#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int cutRope(int n) {
		if (n == 0)	return 0;
		if (n == 1)	return 1;
		if (n == 2)	return 2;
		if (n == 3)	return 3;

		vector<int> rope(n+1, 0);
		rope[0] = 0;
		rope[1] = 1;
		rope[2] = 2;
		rope[3] = 3;

		for (int i = 4; i <= n; i++) {
			int maxProduct = 0;
			for (int j = 1; j <= i / 2; j++) {
				maxProduct = max(maxProduct, rope[j] * rope[i - j]);
			}
			rope[i] = maxProduct;
		}

		return rope[n];
	}
};


//int main() {
//	int ans = Solution().cutRope(8);
//	cout << ans << endl;
//	return 0;
//}