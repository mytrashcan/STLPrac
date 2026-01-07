#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool funnyCompare(const pair<int, int>& a, const pair<int, int>& b) {
	int sumA = (a.first % 2) + (a.first % 3);
	int sumB = (b.first % 2) + (b.first % 3);
	if (sumA != sumB)
		return sumA < sumB;
	else
		return a.second > b.second;
}

bool oddFixedFunnyCompare(const pair<int, int>& a, const pair<int, int>& b) {
	
}

vector<int> funnySort(vector<int> arr) {
	vector<pair<int, int>> vec;
	for (int i = 0; i < arr.size(); i++) {
		vec.push_back({ arr[i], i });
	}
	//sort(vec.begin(), vec.end(), funnyCompare);
	sort(vec.begin(), vec.end(), oddFixedFunnyCompare);
	vector<int> sorted;
	for (pair<int, int>& p : vec) {
		sorted.push_back(p.first);
	}
	return sorted;
}

int main() {
	vector<int> arr = { 15, 10, 6, 12, 9, 4, 18, 24, 2, 3 };
	vector<int> sorted = funnySort(arr);
	for (int num : sorted) {
		cout << num << " ";
	}
	return 0;
}