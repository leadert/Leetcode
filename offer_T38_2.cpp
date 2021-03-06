#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    std::vector<std::string> permutation2(std::string s) {
        // 去重处理
        std::set<std::string> res;
        backtrack2(s, 0, res);

        return std::vector<std::string>(res.begin(), res.end());
    }

    /*
     * 回溯函数
     * 使用set函数对字符串字符进行去重，
     * 使用swap函数交换两个字符
     * */
    void backtrack2(std::string s, int start, std::set<std::string>& res) {
        // 回溯结束条件
        if (start == s.size()) {
            res.insert(s);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            // 做选择
            std::swap(s[i], s[start]);
            // 进入下一次决策树
            backtrack2(s, start + 1, res);
            // 撤销选择
            std::swap(s[i], s[start]);
        }
    }
};

//
//int main() {
//    string s = "aab";
//    vector<string> result = Solution().permutation2(s);
//    for (auto x : result) {
//        cout << x << endl;
//    }
//    return 0;
//}