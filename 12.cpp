#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        int k = num / 1000;   //千位数
        num = num % 1000;
        int h = num / 100;    //百位数 
        num = num % 100;
        int t = num / 10;     //十位数
        int d = num % 10;     //个位数

        string res;
        if (0 < k && k < 4)
            for (int i = 0; i < k; i++) {
                res += "M";
            }

        if (0 < h && h <= 9) {
            while (h > 0) {
                if (h == 9) { res += "CM"; break; }
                else if (5 <= h && h < 9) { res += "D"; h -= 5; }
                else if (h == 4) { res += "CD"; break; }
                else
                {
                    res += "C";
                    h -= 1;
                }
            }
        }

        if (0 < t && t <= 9) {
            while (t > 0) {
                if (t == 9) { res += "XC"; break; }
                else if (5 <= t && t < 9) { res += "L"; t -= 5; }
                else if (t == 4) { res += "XL"; break; }
                else
                {
                    res += "X";
                    t -= 1;
                }
            }
        }
        
        if (0 < d && d <= 9) {
            while (d > 0) {
                if (d == 9) { res += "IX"; break; }
                else if (5 <= d && d < 9) { res += "V"; d -= 5; }
                else if (d == 4) { res += "IV"; break; }
                else
                {
                    res += "I";
                    d -= 1;
                }
            }
        }

        return res;
    }
};

//int main() {
//    int num;
//    cin >> num;
//
//    string res = Solution().intToRoman(num);
//    cout << res;
//}