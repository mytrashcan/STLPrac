#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	cin.ignore();

	for (int k = 0; k < tc; k++) {
		int n;
		cin >> n;
		cin.ignore();

		bool found = false;

		for (int i = 0; i < n; i++) {
			queue<char> qu;
			stack<char> st;
			string s;
			bool valid = true;

			getline(cin, s);

			for (char c : s) {
				qu.push(c);
				st.push(c);
			}

			for (int j = 0; j < s.length(); j++) {
				char quc = qu.front();
				qu.pop();

				char stc = st.top();
				st.pop();

				if (quc != stc) {
					valid = false;
					break;
				}
			}

			if (valid) {
				cout << s << endl;
				found = true;
			}
		}
		if (!found)
			cout << 0 << '\n';
	}
}