#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>
using namespace std;



int n;
int p1, p2;
int m;
vector<vector <int>> relation(100);
bool found = false;
int visited[101] = { 0 };
int ans;

void dfs(int person, int count) {
	visited[person] = true;
	if (person == p2) {
		found = true;
		ans = count ;
		return;
		
	}

	for (int next : relation[person]) {
		if (visited[next]) continue;
		dfs(next, count + 1);
		if (found == true)break;
	}
}

int main(void) {
	cin >> n;
	
	cin >> p1 >> p2;

	cin >> m;

	for (int i = 0; i < m; i++) {
		int u;
		int v;

		cin >> u >> v;

		//기준 노드의 자식이면 1
		//기준 노드의 부모면 0
		relation[u].push_back(v);
		relation[v].push_back(u);
	}


	//dfs
	dfs(p1,0);

	if (found == false) cout << -1 << "\n";
	else {
		cout << ans << "\n";
	}
	return 0;
}
