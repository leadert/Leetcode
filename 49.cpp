#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    // 思路:每个单词用一个质数代替，乘积代表组合唯一值
    //vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //    map<char, int> chToNum = { {'a',2},{'b',3},{'c',5},{'d',7},{'e',11},{'f',13},{'g',17},
    //        {'h',19},{'i',23},{'j',29},{'k',31},{'l',37},{'m',41},{'n',43},
    //        {'o',47},{'p',53},{'q',59},{'r',61},{'s',67},{'t',71},
    //        {'u',73},{'v',79},{'w',83},{'x',89},{'y',97},{'z',101} };

    //    vector<long long> count(strs.size());
    //    vector<int> flag(strs.size());
    //    for (int i = 0; i < (int)strs.size(); i++) {
    //        long long sum = 1;
    //        for (char ch : strs[i]) {
    //            sum *= chToNum[ch];
    //        }
    //        count[i] = sum;

    //        flag[i] = 0;
    //    }

    //    vector<vector<string>> ret;
    //    for (int i = 0; i < (int)count.size(); i++) {
    //        if (flag[i] != 0) 
    //            continue;
    //        //else
    //        vector<string> tmp = { strs[i] };
    //        flag[i] = 1;
    //        for (int j = i + 1; j < (int)count.size(); j++) {
    //            if (count[j] == count[i]) {
    //                tmp.push_back(strs[j]);
    //                flag[j] = 1;
    //            }
    //        }
    //        ret.push_back(tmp);
    //    }
    //    return ret;
    //}

    //思路：哈希表映射，相同字母组成的单词其哈希结果相同
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int sub = 0;
        string tmp;
        unordered_map<string, int> work;

        for (auto str : strs) {
            tmp = str;
            sort(tmp.begin(), tmp.end());
            if (work.count(tmp)) {
                res[work[tmp]].push_back(str);
            }

            else {
                vector<string> vec(1, str);
                res.push_back(vec);
                work[tmp] = sub++;
            }
        }
        return res;
    }
};

//int main() {
//    vector<string> ques = {"rig","rig", "cub"};
//    vector<vector<string>> ret = Solution().groupAnagrams(ques);
//    for (auto str : ret) {
//        for (auto x : str) {
//            cout << x << " ";
//        }
//        cout << endl;
//    }
//}