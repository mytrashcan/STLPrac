/*
문제 설명:
투표 용지 N장이 있습니다. 각 용지에는 후보자의 이름(문자열)이 적혀 있습니다.
누가 몇 표를 받았는지 세어서 출력하세요. (이름 사전 순으로 출력)

입력 예시:

5
Tom
Jerry
Tom
Tom
Mickey

출력 예시:

Jerry: 1
Mickey: 1
Tom: 3
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();
	map<string, int> count;

	for (int i = 0; i < N; i++) {
		string name;
		getline(cin, name);
		/*
		if (count.find(name) != count.end())
			count[name]++;
		else
			count.insert({ name, 1 });
		*/
		count[name]++;
	}

	for (auto it : count) {
		cout << it.first << ": " << it.second << endl;
	}
}