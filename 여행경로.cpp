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
	//dfs 재귀를 끝내는 if문 
	//모든 배열 체크가 완료된 상태면  빠져나가기
	if (count == tickets.size()) { 
		answer = result;
		return;
	}
	int same = 0;
	//현재 노드에서 다음 방문할 노드를 고르는 for문
	for (int i = 0; i < tickets.size(); i++) {
		//for문 안에 다음 방문할 노드 후보들이 방문한 적이 있는지, 방문할 후보가 될 조건을 만족하는지 확인하는 if문
		if (tickets[i][0] == start && !check[i]) {
			same++;
			//세부 조건(예외처리,추가조건)을 만족하는지 묻는 if문
			if (same != 1)continue;
			//방문했다 처리 (check배열에)
			check[i] = true;
			//최종 결과 값을 얻기위해 다음 dfs에 전달해줄 여태까지 구한 result 값 update
			result.push_back(tickets[i][1]);
			//다음 bfs 수행
			dfs(tickets, tickets[i][1],count+1,result);
			result.pop_back();
			//방문했다 처리를 false로 바꿔주기 
			check[i] = false;
		}
	}

}

vector<string> solution(vector<vector<string>> tickets) {
	//첫 dfs 함수 실행을 위한 setting
	//알파벳 순으로 정렬
	sort(tickets.begin(), tickets.end());
	answer.push_back("ICN");
	dfs(tickets, "ICN", 0, answer);
	return answer;
}
