//DFS
//재귀함수

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string target_word;
vector<string> words_list;
bool check[51] = { false };
int answer = 100;

void dfs(string begin, int result) {
	if (target_word == begin) {
		answer = result;
		return;
	}
	for (int i = 0; i < words_list.size(); i++) {
		int count = 0;
		for (int j = 0; j < words_list[i].size(); j++) {
			if (begin[j] != words_list[i][j])count++;
			if (count == 2) break;
		}
		//만약 한글자만 다르고 두글자는 같다면 단어 변환 가능
		if (count == 1) {
			if (check[i] == false) {
				check[i] = true;
				dfs(words_list[i], result + 1);
				check[i] = false;
			}
		}
	}
}


int solution(string begin, string target, vector<string> words) {
	target_word = target;
	words_list = words;
	dfs(begin,0);
	if (answer == 100) answer = 0;
	return answer;
}
