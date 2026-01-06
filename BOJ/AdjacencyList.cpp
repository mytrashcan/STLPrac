#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int M;
	vector<int> adj[100];

	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 정렬해서
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	// 각 vector의 원소 출력 - done
	for (int i = 1; i <= N; i++) {
		cout << i << ": ";
		for (int j = 0; j < adj[i].size(); j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}
