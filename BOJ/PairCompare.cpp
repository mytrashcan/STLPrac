/*
문제 설명:2차원 평면 위의 점 N개가 주어집니다. 
좌표를 pair<int, int>에 담아서 저장하세요.
다음 규칙에 따라 정렬하여 출력하세요.
1. x좌표가 작은 순서대로 (오름차순)
2. 만약 x좌표가 같다면, y좌표가 큰 순서대로 (내림차순)

입력 예시:

5
1 1
3 3
1 5
2 2
3 1
출력 예시:

1 5
1 1
2 2
3 3
3 1
*/
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