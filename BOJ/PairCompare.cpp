#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
		return a.second > b.second;
	else
		return false;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> points;

	for (int i = 0; i < n; i++) {
		int op1; int op2;
		cin >> op1 >> op2;
		points.push_back(pair<int, int>(op1, op2));
	}

	sort(points.begin(), points.end(), cmp);

	for (int i = 0; i < points.size(); i++) {
		cout << points[i].first << " " << points[i].second << endl;
	}
}