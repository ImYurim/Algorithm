//프로그래머스 DFS BFS
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> computers_network;

bool dfs(int n) {
	if (!computers_network[n][n]) return false;
	computers_network[n][n] = 0;

	for (int i = 0; i < computers_network.size(); i++) {
		if (computers_network[n][i]) dfs(i);
	}
	return true;
}

int solution(int n, vector<vector<int>> computers) {

	int answer = 0;
	computers_network = computers;
	for (int i = 0; i < n; i++) {
		if (computers[i][i] && dfs(i))answer++;
	}
	return answer;
}

