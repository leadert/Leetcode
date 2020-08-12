//�Ҵ��ַ����е�������ĸ��λ��
//��������˼�룬p�ַ������ȹ̶�

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
	vector<int> findAndgrams(string s, string p) {
		unordered_map<char, int> need, window;
		for (auto x : p) {
			need[x]++;
		}

		vector<int> res;
		int left = 0, right = 0;
		int valid = 0;

		while (right < s.size()) {
			char c = s[right];
			right++;

			//���������ݸ���
			if (need.count(c)) {
				window[c]++;
				if (window[c] == need[c])
					valid++;
			}

			//�ж�����Ƿ���Ҫ����
			while (right - left >= p.size()) {
				//���ڷ�������ʱ����ʼ��������res
				if (valid == need.size())
					res.push_back(left);
				char d = s[left];
				left++;
				//���������ݸ���
				if (need.count(d)) {
					if (window[d] == need[d])
						valid--;
					window[d]--;
				}
			}
		}
		return res;
	}
};


//int main() {
//	string s = "cbaebabacd";
//	string p = "abc";
//	vector<int> res = Solution().findAndgrams(s, p);
//	for (int i = 0; i < res.size(); i++) {
//		cout << res[i] << " ";
//	}
//}