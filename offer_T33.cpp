#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPostOrder(vector<int>& postorder, int start, int end) {
        if (postorder.empty())   return false;
        if (start == end)    return true;
        int root = postorder[end];
        int i;
        for (i = start; i < end; i++) {
            if (postorder[i] > root) {
                break;
            }
        }

        int j;
        for (j = i; j < end; j++) {
            if (postorder[j] < root) {
                return false;
            }
        }

        bool left = true, right = true;
        if (start <= i - 1) {
            left = isPostOrder(postorder, start, i - 1);
        }
        
        if (i <= end - 1) {
            right = isPostOrder(postorder, i, end - 1);
        }

        return left && right;
    }

    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty())   return true;
        int length = postorder.size() - 1;
        return isPostOrder(postorder, 0, length);
    }
};

//int main() {
//    vector<int> postorder = { 4,6,7,5 };
//    bool flag = Solution().verifyPostorder(postorder);
//    cout << flag << endl;
//    return 0;
//}