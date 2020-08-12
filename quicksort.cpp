#include<iostream>
#include<vector>
using namespace std;


void quickSort(vector<int>& nums, int start, int end) {
	if (start >= end)	return;
	int pivot = nums[start], i = start + 1, j = end;
	while (i <= j) {
		if (nums[i] > pivot && nums[j] < pivot) {
			swap(nums[i++], nums[j--]);
		}
		if (nums[i] <= pivot)	i++;
		if (nums[j] >= pivot)	j--;
	}
	swap(nums[start], nums[j]);
	quickSort(nums, start, j - 1);
	quickSort(nums, j + 1, end);
}

vector<int> sortArray(vector<int>& nums) {
	quickSort(nums, 0, int(nums.size()) - 1);
	return nums;
}


//int main() {
//	vector<int> nums{ 5, 2, 1, 3, 1, 5, 4 };
//	vector<int> ansArray = sortArray(nums);
//	for (auto x : ansArray) {
//		cout << x << " ";
//	}
//	return 0;
//}