#include<iostream>
#include<vector>
using namespace std;

//动态规划，如何想到？共i个节点的二叉搜索树数量=左子树数量（j-1个节点）*右子树数量(i-j个节点)
class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n + 1);
        res[0] = 1;
        res[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                res[i] += res[j - 1] * res[i - j];   //左右子树共i-1个节点；左右子树情况不同
            }
        }

        return res[n];
    }
};