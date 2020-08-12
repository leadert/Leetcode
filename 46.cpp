#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;

        if (nums.empty()) return ret;
        ret.push_back({ nums[0] });
        for (int i = 1; i < nums.size(); i++) {
            vector<vector<int>> iVec;
            for (vector<int> tmpVec : ret) {
                for(int j = 0; j <= tmpVec.size(); j++ ) {
                    vector<int> copyTmpVec = tmpVec;
                    copyTmpVec.insert(copyTmpVec.begin()+j, nums[i]);
                    iVec.push_back(copyTmpVec);
                }
            }
            ret = iVec;
        }
        return ret;
    }
};

//int main() {
//    vector<int> nums = { 1,2,3 };
//    vector<vector<int>> ret = Solution().permute(nums);
//    for (vector<int> tmpVec : ret) {
//        for (int i = 0; i < tmpVec.size(); i++) {
//            cout << tmpVec[i] << " ";
//        }
//        cout << endl;
//    }
//}