#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�ڶ�ά��ͬʱ���͵ı��ڸߵ�ǰ��
//������߽��򣬵ڶ�ά���򣻽�Ԫ�ز����Ӧ�������ڶ�ά����λ��
class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        if (v1[0] == v2[0]) return v1[1] <= v2[1];
        else return v1[0] > v2[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;

        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); i++) {
            res.insert(res.begin() + people[i][1], people[i]);
        }

        return res;
    }
};