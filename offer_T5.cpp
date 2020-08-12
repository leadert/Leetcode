// Ìæ»»¿Õ¸ñ
#include<iostream>
using namespace std;


class Solution {
public:
	void replaceSpace(char str[], int length) {
		if (str == nullptr || length<=0)
			return;

		int originalLength = 0, newlength = 0;
		int i = 0;
		while(str[i] != '\0') {
			if (str[i] == ' ')
				newlength += 2;
			newlength += 1;
			originalLength++;
			++i;
		}

		while (originalLength<newlength) {
			if (str[originalLength - 1] == ' ') {
				str[--newlength] = '0';
				str[--newlength] = '2';
				str[--newlength] = '%';
			}
			else {
				str[--newlength] = str[originalLength-1];
			}
			originalLength--;
		}
	}
};

//int main() {
//	char str[30] = " ";
//	Solution().replaceSpace(str, 30);
//	cout << str;
//	return 0;
//}