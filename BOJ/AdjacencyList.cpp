/*
정점(Node)의 개수 N과 간선(Edge)의 개수 M이 주어집니다.
이어서 M개의 줄에 연결된 두 정점 u, v가 주어집니다. (무방향 그래프)
모든 입력을 받은 후, 각 정점과 연결된 친구들을 오름차순으로 정렬하여 출력하세요

입력 예시:

5 4
1 2
1 5
4 5
2 3
(해석: 1번은 2,5와 연결 / 4번은 5와 연결 ...)

출력 예시:

1: 2 5
2: 1 3
3: 2
4: 5
5: 1 4
*/
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
