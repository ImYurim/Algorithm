//자세한 설명
//https://yulme.tistory.com/90?category=770210

// 기울이면 공이 벽 만날때까지 쭉 미끄러져 내려감
// 필요한 변수 : R과 B의 위치, 몇번만에 0로 나갔는지 셀 count
// #이 아닌 .인곳으로 계속 감. #만나기전까지 쭉 감

#include <iostream>
#include <string> 
#include <queue>
using namespace std;


struct location {
	int red_x;
	int red_y;
	int blue_x;
	int blue_y;
	int depth;
};

//공이 움직이는 방향 상.하.좌.우
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력받을 지도
char map[10][10] = {0};
//입력받을 보드의 가로 세로 크기
int n = 0;
int m = 0;
//현재 빨간공, 파란공 위치
int r_x, r_y, b_x, b_y = 0;
int red_checked[10][10] = {0};
int blue_checked[10][10] = {0};

//빨간공 파란공 위치 및 몇 번째인지가 담긴 큐
queue<location> q;

void move(int &a_x, int &a_y, int &a_d_any ,int dx, int dy) {
	
	while (map[a_x + dx][a_y + dy] != '#' && map[a_x][a_y] != 'O') {
		a_x += dx;
		a_y += dy;
		a_d_any++;
	}
}

void bfs() {
	while (!q.empty()) {
		int r_x = q.front().red_x;
		int r_y = q.front().red_y;
		int b_x = q.front().blue_x;
		int b_y = q.front().blue_y;
		int d = q.front().depth;
		q.pop();
		if (d >= 10) break;

		for (int i = 0; i < 4; i++) {


			//공들의 다음 위치
			int a_r_x = r_x;
			int a_r_y = r_y;
			int a_b_x = b_x;
			int a_b_y = b_y;

			// 공 겹쳤을때 해결 위한 변수 누가 먼저 다음자리에 도착했는지 가려내는 변수
			int a_r_d = 0;
			int a_b_d = 0;

			//공 안겹쳤을 때 몇번째 이동 인지 알려주는 변수
			int a_d = d + 1;

			move(a_r_x, a_r_y, a_r_d, dx[i], dy[i]);
			move(a_b_x, a_b_y, a_b_d, dx[i], dy[i]);

			// 가장 해줄 거 없는 애부터 if문 가장먼저오게
			if (map[a_b_x][a_b_y] == 'O') {
				continue;
			}
			if (map[a_r_x][a_r_y] == 'O') {
				printf("%d", a_d);
				return;
			}
			if (a_r_x == a_b_x && a_r_y == a_b_y) {
				if (a_r_d < a_b_d) {
					a_b_x -= dx[i];
					a_b_y -= dy[i];
				}
				else {
					a_r_x -= dx[i];
					a_r_y -= dy[i];
				}
			}
			if (red_checked[a_r_x][a_r_y] == 1 && blue_checked[a_r_x][a_r_y] == 1) continue;
			else {
				red_checked[a_r_x][a_r_y] = 1;
				blue_checked[a_r_x][a_r_y] = 1;
				q.push({ a_r_x,a_r_y,a_b_x,a_b_y,a_d });
			}

		}




	}
	printf("-1\n");
}


int main() {


	//빨간공, 파란공이 갔던 위치를 알기 위한 큐


	//보드의 가로 세로 입력
	printf("가로 세로 : ");
	scanf("%d %d", &n, &m);

	//맵 입력
	printf("map : ");
	for (int i = 0; i < n; i++) {
		printf("\n");
		for (int j = 0; j < m; j++) {
			scanf("%1s", &map[i][j]);
			if (map[i][j] == 'R') {
				r_x = i;
				r_y = j;
			}
			else if (map[i][j] == 'B') {
				b_x = i;
				b_y = j;
			}
		}

	}

	q.push({ r_x, r_y, b_x, b_y,0 });
	red_checked[r_x][r_y] = 1;
	blue_checked[b_x][b_y] = 1;
	bfs();
	return 0;
}
