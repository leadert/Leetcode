#include<iostream>
using namespace std;

class Solution {
public:
	bool equal(double num1, double num2) {
		if (fabs(num1 - num2) < 0.000001) {
			return true;
		}
		return false;
	}


	double powerWithAbsExponent(double base, unsigned int exponent) {
		if (exponent == 0)	return 1;
		if (exponent == 1)	return base;

		double result = powerWithAbsExponent(base, exponent >> 1);
		result *= result;
		if ((exponent & 0x1) == 1)	result *= base;
		return result;
	}


	double power(double base, int exponent) {
		if (equal(base, 0.0) && exponent < 0) {
			return 0.0;
		}

		unsigned int absExponent = (unsigned int)exponent;
		if (exponent < 0)	absExponent = (unsigned int)(-exponent);

		double ans = powerWithAbsExponent(base, absExponent);
		if (exponent < 0)	ans = 1.0 / ans;

		return ans;
	}
};