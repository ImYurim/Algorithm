//프로그래머스 
//DFS
//단어변환 문제와 비슷함

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<string>answer;



bool check[10000] = { false };

void dfs(vector<vector<string>>tickets,string start,int count , vector<string>result) {
	//모든 배열 체크가 완료된 상태면  빠져나가기
	if (count == tickets.size()) { 
		answer = result;
		return;
	}
	int same = 0;
	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == start && check[i]==false) {
			same++;
			if (same != 1)continue;
			check[i] = true;
			result.push_back(tickets[i][1]);
			dfs(tickets, tickets[i][1],count+1,result);
			result.pop_back();
			check[i] = false;
		}
	}

}

vector<string> solution(vector<vector<string>> tickets) {

	//알파벳 순으로 정렬
	sort(tickets.begin(), tickets.end());
	answer.push_back("ICN");
	dfs(tickets, "ICN", 0, answer);
	return answer;
}
