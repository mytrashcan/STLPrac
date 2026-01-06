#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


int main() {
	short int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		stack<char> s;
		string ps;
		getline(cin, ps);

		for (char c : ps) {
			if (c == '(') {
				s.push(c);
			}
			else if (c == ')') {
				if (s.empty()) {
					s.push(c);
					break;
				}
				else {
					s.pop();
				}
			}
		}

		if (s.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
}
