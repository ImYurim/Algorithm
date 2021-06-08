#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int N;
int M;
vector<string> people;
map<string, int> idx;
vector<vector<int>> graphtemp(1005);
int in[1005];
vector<vector<int>> ans(1005);

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		people.push_back(s);
	}

	sort(people.begin(),people.end());

	cin >> M;

	for (int i = 0; i < N; i++) {
		idx[people[i]] = i;
	}

	for (int i = 0; i < M; i++) {
		string n1, n2;
		cin >> n1 >> n2;
		int child = idx[n1];
		int parent = idx[n2];
		graphtemp[parent].push_back(child);
		in[child]++;
	}
	queue<int> nextparent;
	vector<int> superparent;

	for (int i = 0; i < N; i++) {
		if (in[i] == 0) {
			superparent.push_back(i);
			nextparent.push(i);
		}
	}

	while (!nextparent.empty()) {
		int parent = nextparent.front();
		nextparent.pop();
		for (int child : graphtemp[parent]) {
			in[child]--;
			if (in[child] == 0) {
				ans[parent].push_back(child);
				nextparent.push(child);
			}
		}
	}

	cout << superparent.size() << '\n';
	for (int i: superparent) {
		cout << people[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < N; i++) {
		cout << people[i] << ' ' << ans[i].size() << ' ';
		sort(ans[i].begin(), ans[i].end());
		for (int j : ans[i]) {
			cout << people[j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
