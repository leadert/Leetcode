#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	vector<int>	leftHighNum(vector<int>& nums) {
		if (nums.size() == 1)	return { -1 };

		vector<int> result(nums.size(), -1);
		stack<int> numStack;
		for (int i = 0; i < nums.size(); i++) {
			while (!numStack.empty() && nums[i] > numStack.top()) {
				numStack.pop();
			}
			if (!numStack.empty()) {
				result[i] = numStack.top();
			}
			numStack.push(nums[i]);
		}

		return result;
	}
};


//int main(){
//	int n;
//	while (cin >> n && n>=1) {
//		vector<int> nums(n);
//		int i = 0;
//		cin >> nums[i++];
//		while(cin.get()!='\n') {
//			cin>>nums[i++];
//		}
//
//		vector<int> ret = Solution().leftHighNum(nums);
//		for (auto x: ret) {
//			cout << x << " ";
//		}
//		cout << endl;
//	}
//}