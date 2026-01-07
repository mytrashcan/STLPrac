/*
베스트셀러 순위 매기기
상황: 서점에서 오늘 팔린 책들의 제목이 입력됩니다.

1 가장 많이 팔린 책 순서대로 출력하세요. (판매량 내림차순)
2 판매량이 같다면, 책 제목 사전 순으로 출력하세요. (제목 오름차순)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second > b.second) return true;
	else if (a.second == b.second)
		return a.first < b.first;
	return false;
}

int main() {
	int N;
	cin >> N;
	cin.ignore();

	map<string, int> counts;
	for (int i = 0; i < N; i++) {
		string title;
		getline(cin, title);
		counts[title]++;
	}

	vector<pair<string, int>> v;

	for (auto p : counts)
		v.push_back(p);

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) 
		cout << v[i].first << " (" << v[i].second << ")\n";
}