#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0)  return 0;

        int maxInterest = 0;
        int minValue = prices[0];

        for (int i = 1; i < len; i++) {
            maxInterest = max(maxInterest, prices[i]-minValue);
            minValue = min(minValue, prices[i]);
        }

        return maxInterest;
    }
};


//int main() {
//    vector<int> prices{ 7,1,5,3,6,4 };
//    int maxValue = Solution().maxProfit(prices);
//    cout << maxValue;
//    return 0;
//}