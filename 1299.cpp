#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.empty()) return{};

        int len = arr.size();
        vector<int> ret(len, -1);
        int rightMaxValue = arr[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            ret[i] = rightMaxValue;
            rightMaxValue = max(arr[i], rightMaxValue);
        }
        return ret;
    }
};

//int main() {
//    int n;
//    cin >> n;
//    while (n--) {
//        vector<int> arr;
//        int tmp;
//        cin >> tmp;
//        arr.push_back(tmp);
//        while (cin.get() != '\n') {
//            cin >> tmp;
//            arr.push_back(tmp);
//        }
//        vector<int> result = Solution().replaceElements(arr);
//        for (auto x : result) {
//            cout << x << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}