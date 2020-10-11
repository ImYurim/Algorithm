//주사위 로직
//남,북으로 움직일때는 주사위 양옆은 바뀌지 않는다.
//동, 서로 움직일때는 주사위 앞뒤는 바뀌지 않는다.
//각 면의 숫자를 저장하는 배열을 하나 만든다.
//동, 서, 남, 북 각 방향으로 움직일 때 어떻게 배열의 숫자가 바뀌어야하는지 각 방향마다 로직을 만든다. 

//동 : 1, 서 : 2, 북 : 3, 남 : 4 
#include <iostream>
#include <vector>
using namespace std;


int n = 0;
int m = 0;
int x = 0;
int y = 0;
int k = 0;

int map[20][20] = { 0 };
int order[1000] = { 0 };
//동서북남
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
//
vector<int> dice = {0,0,0,0,0,0};
//swap위한 tempt dice
vector<int> t_dice = { 0,0,0,0,0,0 };


void move() {
	for (int l = 0; l < k; k++) {
		int nx = x + dx[l];
		int ny = y + dy[l];
		if (nx<0 || nx>n || ny<0 || ny>m)continue;

		switch (order[l]) {
		case 1:
			
		}

	}
}

int main() {
	scanf("%d %d %d %d %d", &n,&m,&x,&y,&k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int l = 0; l < k; k++) {
		scanf("%d", &order[k]);
	}

	move();
	return 0;







}

