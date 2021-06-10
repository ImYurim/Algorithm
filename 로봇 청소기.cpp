#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
int now_d;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int x, y;
int room[50][50];
int done[50][50] = { 0 };
bool finished = false;
int ans = 0;

int main(void) {
	cin >> N >> M;
	
	cin >> x >> y;
	


	cin >> now_d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
		}
	}

	
	

	while (true) {
		if (finished)break;


		//현재 있는 자리 청소 가능
		if (!room[x][y] && !done[x][y]) {
			done[x][y] = 1;
			ans++;

		}

		//청소 불가 또는 청소 후
		for (int i = 0; i < 4; i++) {
			//왼쪽 방향 틀기
			int next_d = now_d - 1;
			if (next_d < 0)next_d = 3;

			int nx = x + dx[next_d];
			int ny = y + dy[next_d];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!room[nx][ny] && !done[nx][ny]) {
					x = nx;
					y = ny;
					now_d = next_d;
					break;
				}
				now_d = next_d;
				

			}

			if (i == 3) {
				nx = x - dx[now_d];
				ny = y - dy[now_d];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && !room[nx][ny]) {
					x = nx;
					y = ny;
				}
				else {
					finished = true;
				}
			}
		}




	}
	cout << ans;
	return 0;
}
