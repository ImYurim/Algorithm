#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>
using namespace std;

int N, M, V;
int ans_dfs[1001];
int ans_bfs[1001];
vector<vector<int>> node(1001);
queue<int> q;
int visited[1001] = { 0 };

void dfs(int V) {
	visited[V] = 1;
	cout << V << " ";

	for (int child : node[V]) {
		if (visited[child])continue;
		dfs(child);
	}
}

void bfs(int V) {
	cout << V << " ";
	while (!q.empty()) {
		int nextnode = q.front();
		q.pop();
		for (int child : node[nextnode]) {
			if (visited[child])continue;
			q.push(child);
			visited[child] = 1;
			cout << child << " ";
		}
		
	}
}

int main(void) {
	cin >> N >> M >> V;


	for (int i = 0; i < M; i++) {
		int u;
		int v;

		cin >> u >> v;

		node[u].push_back(v);
		node[v].push_back(u);

	}

	for (int i = 1; i <= N; i++) {
		sort(node[i].begin(), node[i].end());
	}

	//dfs
	dfs(V);
	cout << "\n";
	
	memset(visited, 0, sizeof(visited));

	q.push(V);
	visited[V] = 1;
	//bfs
	bfs(V);

	return 0;
}
