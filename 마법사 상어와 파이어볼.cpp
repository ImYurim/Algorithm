//
//  main.cpp
//  algorithm
//
//  Created by 임유림 on 2021/01/03.
//

#include <iostream>
#include <vector>
using namespace std;

typedef struct FIREBALL
{
    int x;
    int y;
    int m;
    int s;
    int d;
} FIREBALL;

int N = 0;
int M = 0;
int K = 0;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int f_d_t[4]={0,2,4,6};
int f_d_f[4]={1,3,5,7};

vector<FIREBALL> MAP[50][50];
vector<FIREBALL> fireball;


int main()
{

    scanf("%d %d %d", &N, &M, &K);



    int x, y, m, s, d;

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d %d %d", &x, &y, &m, &s, &d);
        //구조체 원소들 중괄호 이용해서 push_back
        fireball.push_back({x, y, m, s, d});
        MAP[x][y].push_back({x, y, m, s, d});
    }

    for (int i = 0; i < K; i++)
    {
        for(int m=1;m<=N;m++){
            for(int n=1;n<=N;n++){
                //칸마다 vector 들어있는거 삭제하기
                MAP[m][n].clear();
            }
        }
        
        for (int l = 0; l < fireball.size(); l++)
        {
            int r = fireball[l].x;
            int c = fireball[l].y;
            int speed = fireball[l].s;
            int dir = fireball[l].d;

            int move = speed % N;
            int nx = r + dx[dir] * move;
            int ny = c + dy[dir] * move;

            if (nx > N)
                nx -= N;
            if (ny > N)
                ny -= N;

            //map의 가장 왼쪽 위에 좌표는 (1,1)이다. (0,0) 아님!
            if (nx < 1)
                nx += N;
            if (ny < 1)
                ny += N;
            
            fireball[l].x = nx;
            fireball[l].y = ny;
            
            //struct vector 타입이 들어가는 배열 MAP에 struct vector 넣기
            MAP[nx][ny].push_back(fireball[l]);


        }
        //파이어볼 이동
        //2개이상 파이어볼이 있는 경우 -> 합쳐진 후 4개로 쪼개짐
        //질량 = 질량합/5 내림 (질량0이면 없어짐)
        //속력  =  속력합/파이어볼개수 내림
        //방향이 모두 짝수나 홀수면  0,2,4,6 그 외 1,3,5,7
        vector<FIREBALL> temp;
        for (int j = 1; j <= N; j++)
            {
            for (int k = 1; k <= N; k++)
            {

                if(MAP[j][k].size()==0)continue;
                if(MAP[j][k].size()==1){
                    //MAP[j][k][0] : map배열에서 (j,k)에 위치하는 vector의 가장 첫번째 구조체
                    temp.push_back(MAP[j][k][0]);
                    continue;
                }
                
                int f_m=0;
                int f_s=0;
                
                //'모두 짝수이거나 모두 홀수일때 ~를 해라'라는 조건에서는 true로 초기화
                bool even=true;
                bool odd=true;

                //한칸에 있는 애들 다 돌면서 하나로 합치기
                for(int p=0;p<MAP[j][k].size();p++){
                    f_m+=MAP[j][k][p].m;
                    f_s+=MAP[j][k][p].s;
                    if(MAP[j][k][p].d%2==0){
                        odd=false;
                    }
                    else{
                        even=false;
                    }
                    
                }
                f_m=f_m/5;
                if(f_m==0)continue;
                f_s=f_s/MAP[j][k].size();
                if(even==true||odd==true){
                    for(int p=0;p<4;p++){
                        temp.push_back({j,k,f_m,f_s,f_d_t[p]});
                        
                    }

                }else{
                    for(int p=0;p<4;p++){
                        temp.push_back({j,k,f_m,f_s,f_d_f[p]});
                        
                    }
                }
                    
                
            }
        }
        fireball=temp;
    }
    int sum_m=0;
    //남은 fireball 질량
    for(int b=0;b<fireball.size();b++){
        sum_m+=fireball[b].m;
    }
    printf("%d",sum_m);
}
