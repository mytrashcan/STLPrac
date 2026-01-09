#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct vertex {
	vector<vertex*> alist;
	string name;
	vertex(string s): name(s){}
};

class Graph {
public:
	typedef map<string, vertex*> gmap;
	gmap agraph;
	void add_vertex(const string&);
	void add_edge(const string& from, const string& to);
	bool is_connected();
	void DFS(string, vector<vertex*>&);
	void BFS(string);
};

void Graph::add_vertex(const string& name){
	gmap::iterator iter = agraph.find(name);
	if (iter == agraph.end()) {
		vertex* x;
		x = new vertex(name);
		agraph[name] = x;
		return;
	}
	cout << "\nDuplicate vertex key: " << name;
}

void Graph::add_edge(const string& from, const string& to){
	vertex* f = (agraph.find(from)->second);
	vertex* t = (agraph.find(to)->second);
	f->alist.push_back(t);
	t->alist.push_back(f);
}

void Graph::DFS(string source, vector<vertex*>& visited){
	// dfs
	// 방문 처리 -> 인접 노드로 이동 -> 재귀
	vertex* curr = agraph[source];
	visited.push_back(curr);

	for (vertex* next : curr->alist) {
		if (find(visited.begin(), visited.end(), next) == visited.end())
			DFS(next->name, visited);
	}
}

void Graph::BFS(string source){
	queue<vertex*> q;
	vector<vertex*> visited;

	vertex* curr = agraph[source];
	q.push(curr);
	visited.push_back(curr);


	while (!q.empty()) {
		vertex* temp = q.front();
		q.pop();
		for (vertex *next : temp->alist) {
			if (find(visited.begin(), visited.end(), next) == visited.end()) {
				visited.push_back(next);
				q.push(next);
			}
		}
	}
}

bool Graph::is_connected(){
	if (agraph.empty()) return true;
	vector<vertex*> visited;
	DFS(agraph.begin()->first, visited);
	return agraph.size() == visited.size();
}

int main() {
	Graph g;
	g.add_vertex("A");
	g.add_vertex("B");
	g.add_vertex("C");
	g.add_vertex("D");

	g.add_edge("A", "B");
	g.add_edge("B", "C");

	// 현재 상태: A-B-C   D (D가 떨어져 있음)

	if (g.is_connected()) cout << "이 그래프는 연결되어 있습니다.\n";
	else cout << "이 그래프는 끊겨 있습니다.\n"; // 출력 예상

	g.add_edge("C", "D");
	// 현재 상태: A-B-C-D (모두 연결됨)

	if (g.is_connected()) cout << "이 그래프는 연결되어 있습니다.\n"; // 출력 예상
	else cout << "이 그래프는 끊겨 있습니다.\n";

	return 0;
}