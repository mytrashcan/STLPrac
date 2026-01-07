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
		for(int i = 1 ; i <= N; i++)
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
	int N, M;
	cin >> N >> M;

	Graph g(N);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v);
	}

	g.sortEdges();

	cout << "DFS 결과: ";
	g.dfs(1);
	cout << endl;

	g.resetVisited();

	cout << "BFS 결과: ";
	g.bfs(1);
	cout << endl;

	cout << "연결 요소 개수: " << g.countConnectedComponents() << "\n";
}