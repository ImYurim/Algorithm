//자세한 설명
//https://yulme.tistory.com/92

//bfs 함수 로직
//상하좌우에 먹을 물고기 탐색 
//1. 먹을 물고기 있는 경우
//1-1. 상하좌우에 먹을 물고기 큐에 다 넣은 후 우선순위 큐를 사용해서 우선순위 높은 애 POP
//1-2. 물고기 먹은 후 큐 비워주기 & 갔던 길 체크 초기화 해주기
//2. 먹을 물고기 없는 경우
//2-1.지나갈 수 있는 칸 있는 경우
//2-1-1. 지나갈 칸 큐에 넣기 -> 1번부터 다시 반복
//2-1-2. 지나갈 수 있는 칸이 아예 없으면 종료


#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

struct fish {
	int d;
	int x;
	int y;

	//우선순위 큐 default는 최대힙 이므로 원래 우선순위큐에서 < 연산자는 내림차순정리해주는 앤데 
	//그 operator < 를 최소힙으로 바꿔주는 작업해야함
	bool operator < (const fish &f) const {
		if (d == f.d) {
			if (x == f.x) {
				return y > f.y; //y값 기준으로 오름차순 (최소힙)
			}
			else return x > f.x; //x값 기준으로 오름차순 
		}
		else return d > f.d; //d값 기준으로 오름차순
	}
};


int n = 0;
int map[20][20] = { 0 };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int check[20][20] = { 0 };

//상어 크기
int body = 2;
//상어 몇 번 움직였는지
int m = 0;
//상어 몇 번 물고기 먹었는지
int eat = 0;

priority_queue<fish> q;

void bfs() {
	while (!q.empty()) {
		int d = q.top().d;
		int x = q.top().x;
		int y = q.top().y;
		q.pop();
		
		if (map[x][y] > 0 && map[x][y] < body) {
			eat++;
			map[x][y] = 0;
			if (body == eat) {
				body++;
				eat = 0;
			}
			//상어가 고기 먹기까지 얼마나 움직였는지 (d)를 최종 답에 더해줌
			m += d;

			//물고기를 먹으려고 움직였으니 움직인 후 지금 위치부터 다시 주위 물고기까지의 거리를 재야하니까 초기화해줌
			d = 0;
			//갔던 길도 초기화
			memset(check, false, sizeof(check));
			//움직이기 전 상어 위치에서 먹힐 물고기들 후보들 있던 queue를 비워줌 움직인 후이므로 
			//움직인 후의 지금 자리를 기준으로 새로 채워야함
			while (!q.empty()) q.pop();
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//큐에 안 넣는 경우
			//1.맵 범위 벗어날때
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			//2.이미 방문했던 곳일 때
			if (check[nx][ny])continue;
			//3.상어 크기보다 큰 물고기가 있는 곳일 때
			if (0 < map[nx][ny] && map[nx][ny] > body) continue;

			//큐에 넣는 경우 = 갈 수 있는 곳인 경우 (상어보다 크기가 작거나 같은 물고기가 있는 곳)
			q.push({ d+1,nx,ny });
			check[nx][ny] = true;
		}

	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				q.push({ 0,i,j });
				map[i][j] = 0;
			}
		}
	}
	bfs();
	printf("%d", m);
	return 0;

}
