#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (auto coin : coins) {
			for (int i = 1; i <= amount; i++) {
				if (coin <= i) {
					dp[i] += dp[i - coin];
				}
			}
		}
		return dp[amount];
	}
};


//int main() {
//	int amount;
//	while (cin >> amount) {
//		vector<int> coins;
//		int tmp;
//		cin >> tmp;
//		coins.push_back(tmp);
//		while (cin.get() != '\n') {
//			cin >> tmp;
//			coins.push_back(tmp);
//		}
//		tmp = Solution().change(amount, coins);
//		cout << tmp << endl;
//	}
//	return 0;
//}