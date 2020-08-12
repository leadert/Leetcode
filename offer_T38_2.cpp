#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    std::vector<std::string> permutation2(std::string s) {
        // ȥ�ش���
        std::set<std::string> res;
        backtrack2(s, 0, res);

        return std::vector<std::string>(res.begin(), res.end());
    }

    /*
     * ���ݺ���
     * ʹ��set�������ַ����ַ�����ȥ�أ�
     * ʹ��swap�������������ַ�
     * */
    void backtrack2(std::string s, int start, std::set<std::string>& res) {
        // ���ݽ�������
        if (start == s.size()) {
            res.insert(s);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            // ��ѡ��
            std::swap(s[i], s[start]);
            // ������һ�ξ�����
            backtrack2(s, start + 1, res);
            // ����ѡ��
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