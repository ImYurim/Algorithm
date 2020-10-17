//프로그래머스 
//DFS
//단어변환 문제와 비슷함

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
queue<string>answer;


bool check[10000] = { false };

void dfs(vector<vector<string>>tickets,string start,int count , queue<string>result) {
	//모든 배열 체크가 완료된 상태면  빠져나가기
	if (count == tickets.size()) { 
		answer = result;
		return;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == start && check[i]==false) {
			check[i] = true;
			result.push(tickets[i][0]);
			dfs(tickets, tickets[i][1],count+1,result);
			result.pop();
			check[i] = false;
		}
	}
	return;

}

queue<string> solution(vector<vector<string>> tickets) {

	//알파벳 순으로 정렬
	sort(tickets.begin(), tickets.end());
	//출발지가 ICN인 티켓이 여러장일 경우 가장 알파벳순이 빠른 애를 출발로
	int i;
	for (i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == "ICN") {
			check[i] = true;
			break;
		}
	}
	answer.push("ICN");
	dfs(tickets,tickets[i][1],0,answer);
	return answer;
}
