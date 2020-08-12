#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};

        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> res;
        vector<int> blockUse = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if (left <= blockUse[1]) {
                blockUse[1] = right > blockUse[1] ? right : blockUse[1];
            }

            else {
                res.push_back(blockUse);
                blockUse = { left, right };
            }
        }
        res.push_back(blockUse);
        return res;
    }
};