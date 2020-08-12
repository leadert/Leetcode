#include<iostream>
using namespace std;

int fibonacci(int n) {
	if (n == 0)	return 0;
	if (n == 1)	return 1;

	int fibOne = 0;
	int fibTwo = 1;
	int fibN = 0;
	for (int i = 2; i <= n; i++) {
		fibN = fibOne + fibTwo;
		fibOne = fibTwo;
		fibTwo = fibN;
	}

	return fibN;
}

//int main() {
//	int ans = fibonacci(6);
//	cout << ans;
//	return 0;
//}