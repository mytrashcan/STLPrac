/*
정점(Node)의 개수 N과 간선(Edge)의 개수 M이 주어집니다.
이어서 M개의 줄에 연결된 두 정점 u, v가 주어집니다. (무방향 그래프)
모든 입력을 받은 후, 각 정점과 연결된 친구들을 오름차순으로 정렬하여 출력하세요

입력 예시:
===========================
5 4
1 2
1 5
4 5
2 3
===========================
6 4
1 2
2 5
3 4
4 6
===========================
6 4
1 2
3 4
4 5
3 5
===========================
출력 예시:
===========================
1: 2 5
2: 1 3
3: 2
4: 5
5: 1 4
===========================

===========================

===========================
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[101];
bool visited[101];

void dfs(int c) {
	visited[c] = true;
	cout << c << " ";
	// for (int next : adj[c]) {};
	for (int i = 0; i < adj[c].size(); i++) {
		int next = adj[c][i];
		if (!visited[next])
			dfs(next);
	}
}

void bfs(int c) {
	queue<int> q;

	q.push(c);
	visited[c] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int next : adj[cur]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int N;
	int M;
	//vector<int> adj[100];

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

	cout << "DFS 결과: ";
	dfs(1);
	cout << endl;

	for (int i = 0; i <= N; i++) visited[i] = false;

	cout << "BFS 결과: ";
	bfs(1);
	cout << endl;

	// 연결 요소 개수
	int count = 1;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			count++;
			dfs(i); // 떨어진 연결요소 visited 수정
		}
	}
	cout << "\n연결 요소는 " << count << "개 존재\n";

	// is_connected?
	if (count == 1)
		cout << "이 그래프는 '연결 그래프(Connected Graph)\n";
	else
		cout << "이 그래프는 끊어져 있습니다.\n";

	// (번외) count 변수 안 쓰고 확인하는 법
	bool connected = true;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			connected = false;
			break;
		}
	}

	if (connected) cout << "YES\n";
	else cout << "NO\n";
}
