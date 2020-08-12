#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector <int>> ret;
        if (candidates.size() == 0) return ret;

        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i++) {
            if (target < candidates[i]) break;
            else {
                int k = target / candidates[i];
                if (target % candidates[i] == 0) {
                    vector<int> tmpVec;
                    for (int tmp = 0; tmp < k; tmp++) {
                        tmpVec.push_back(candidates[i]);
                    }
                    ret.push_back(tmpVec);
                }

                for (int j = 1; j < k; j++) {
                    vector<int> tmpVec;
                    tmpVec.assign(candidates.begin() + i + 1, candidates.end());
                    vector<vector<int>> tmp = combinationSum(tmpVec, target - candidates[i] * j);
                    for (vector<int> t : tmp) {
                        for (int n = 0; n < j; n++) {
                            t.push_back(candidates[i]);
                        }
                        ret.push_back(t);
                    }
                }
            }
        }
        return ret;
    }
};


//int main() {
//    vector<int> candidates = { 2,3,5 };
//    vector<vector<int>> ret = Solution().combinationSum(candidates, 8);
//    for (vector<int> tmpVec : ret) {
//        for (int i = 0; i < tmpVec.size(); i++) {
//            cout << tmpVec[i];
//        }
//        cout << endl;
//    }
//}