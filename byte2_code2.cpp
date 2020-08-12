#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	bool validStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> s;
		int j = 0;
		for (int i = 0; i < pushed.size(); i++) {
			s.push(pushed[i]);
			while (!s.empty() && s.top() == popped[j]) {
				s.pop();
				j++;
			}
		}

		return s.empty();
	}
};

//int main() {
//	int n;
//	cin >> n;
//	while (n--) {
//		vector<int> nums1, nums2;
//		int tmp;
//		cin >> tmp;
//		nums1.push_back(tmp);
//		while(cin.get() != '\n') {
//			cin >> tmp;
//			nums1.push_back(tmp);
//		}
//
//		cin >> tmp;
//		nums2.push_back(tmp);
//		while (cin.get() != '\n') {
//			cin >> tmp;
//			nums2.push_back(tmp);
//		}
//
//		bool flag = Solution().validStackSequences(nums1, nums2);
//		if (flag)	cout<<"Y"<<endl;
//		else cout<<"N"<<endl;
//	}
//	return 0;
//}