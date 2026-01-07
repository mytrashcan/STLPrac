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

vector<int> oddFixedFunnyCompare(vector<int>& arr) {
	vector<pair<int, int>> evenArr;
	for (int i = 0; i < arr.size(); i++) {
		if(arr[i] % 2 == 0)
			evenArr.push_back({ arr[i], i });
	}
	sort(evenArr.begin(), evenArr.end(), funnyCompare);

	vector<int> sorted(arr.size());
	int idx = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % 2 == 0)
			sorted[i] = evenArr[idx++].first;
		else
			sorted[i] = arr[i];
	}
	return sorted;
}

vector<int> funnySort(vector<int> arr) {
	vector<pair<int, int>> vec;
	for (int i = 0; i < arr.size(); i++) {
		vec.push_back({ arr[i], i });
	}
	sort(vec.begin(), vec.end(), funnyCompare);
	vector<int> sorted;
	for (pair<int, int>& p : vec) {
		sorted.push_back(p.first);
	}
	return sorted;
}

int main() {
	vector<int> arr = { 15, 10, 6, 12, 9, 4, 18, 24, 2, 3 };
	//vector<int> sorted = funnySort(arr);
	vector<int> sorted = oddFixedFunnyCompare(arr);
	for (int num : sorted) {
		cout << num << " ";
	}
	return 0;
}