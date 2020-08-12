#include<iostream>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
    // 找规律方法，分组计算。速度快
    /*string convert(string s, int numRows) {
        if (s.empty()) return "";
        else if (numRows == 1) return s;
        else {
            string finalS = "";
            int roundCount = 2 * numRows - 2;
            int roundNum = s.size() / roundCount;
            int remaind = s.size() % roundCount;
            for (int row = 0; row < numRows; row++) {
                for (int t = 0; t < roundNum; t++) {
                    string tmpStr = s.substr(t * roundCount, roundCount);
                    finalS += tmpStr[row];
                    if (row != 0 && row != (numRows - 1))
                        finalS += tmpStr[2 * numRows - 2 - row];
                }
                if (numRows >= remaind && remaind > row)
                    finalS += s[roundNum * roundCount + row];
                else if(remaind>numRows)
                    finalS += s[roundNum * roundCount + row];
                if (row != 0 && row != (numRows-1) && (roundNum * roundCount + 2 * numRows - 2 - row) < s.size())
                    finalS += s[roundNum*roundCount+2*numRows-2-row];
            }
            return finalS;
        }
    }*/

    //利用flag，设置numRows个数组，最后合并。直观但是速度慢
    string convert(string s, int numRows) {
        if (s.size() < 2 || numRows == 1) return s;

        vector<char> tmpVec;
        vector<vector<char>> str(numRows, tmpVec);
        int flag = -1;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            str[i].push_back(s[j]);
            if (i == 0 || i == numRows - 1) flag = -flag;
            i += flag;
        }
        
        string finalS;
        for (int j = 0; j < numRows; j++) {
            for (int k = 0; k < str[j].size(); k++)
                finalS += str[j][k];
        }
        return finalS;
    }
};


//int main() {
//    string s;
//    cin >> s;
//    int rowNum;
//    cin >> rowNum;
//
//    Solution a;
//    string res = a.convert(s, rowNum);
//    cout << res << endl;
//}