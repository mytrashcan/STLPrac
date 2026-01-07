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
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
private:
	int N;
	vector<vector<int>> adj;
	vector<bool> visited;
public:
	Graph(int n) {
		N = n;
		adj.resize(N + 1);
		visited.resize(N + 1, false);
	}

	void addEdge(int u, int v) {
		// 무방향
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sortEdges() {
		for (int i = 1; i <= N; i++)
			sort(adj[i].begin(), adj[i].end());
	}

	void resetVisited() {
		fill(visited.begin(), visited.end(), false);
	}

	void dfs(int c) {
		visited[c] = true;
		cout << c << " ";
		for (int next : adj[c])
			if (!visited[next])
				dfs(next);
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

	int countConnectedComponents() {
		resetVisited();
		int count = 0;

		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				count++;
				dfs(i);
			}
		}
		return count;
	}
};

int main() {
	int N, M, C;
	cin >> N >> M >> C;

	Graph g(N);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v);
	}

	g.sortEdges();

	//cout << "DFS 결과: ";
	g.dfs(C);
	cout << endl;

	g.resetVisited();

	//cout << "BFS 결과: ";
	g.bfs(C);
	cout << endl;
}