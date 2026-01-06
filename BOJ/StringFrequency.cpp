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