//인접한 칸은 위, 아래, 왼, 오
//인접한 칸에 2개이상 얼음 없는 칸이 있으면 해당 칸은 얼음 양이 1 줄어듬

//출력
//남아있는 얼음의 합
//남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수 -> DFS

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N,Q;
int A[35][35];
int L[1000];
int sum=0;
int visited[35][35]={0};
int max_ice=0;
int ans_ice=0;

//위 아래 왼 오
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main(){
    scanf("%d %d",&N,&Q);
    N=pow(2,N);
    for (int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&A[i][j]);
        }
    }
    
    //L 1번마다 격자 나누고 각격자 안에서 90도씩 회전
    for(int i=0;i<Q;i++){
        scanf("%d",&L[i]);
        int l = L[i];
 
        //가로 세로 몇의 격자인지
        l = pow(2,l);
        

        //각 격자안에 애들 90도 회전
        int temp[l][l];
        
        //각 격자 안의 맨 왼쪽 위에 애를 시작점으로 해주는 for문 2개
        for(int i=0;i<N;i+=l){
            for(int j=0; j<N;j+=l){
                
                //map에 있는 것 90도 회전 후 temp에 넣어주기
                for(int m=0;m<l;m++){
                    for(int n=0;n<l;n++){
                        temp[n][l-m-1]=A[i+m][j+n];
                    }
                }
                
                //temp에 있는 것 다시 map에 넣어주기
                for(int m=0;m<l;m++){
                    for(int n=0;n<l;n++){
                        A[i+m][j+n]=temp[m][n];
                    }
                }
            }
            
        }
    

        
        //각 칸을 돌면서 인접한 칸 중 2개이상 얼음 없는 칸이 있으면 얼음 양 1 줄어들게하기
        
        int nx;
        int ny;
        vector<pair<int,int>> iceminus;
        
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                int ice=0;
                //얼음이 아예 없는 칸이면 주위에 얼음이 있는지 확인 안하고 넘겨야함
                if(A[i][j]==0) continue;
                for(int k=0; k<4; k++){
                    nx = i + dx[k];
                    ny = j + dx[k];
                    if (nx<0||nx>N||ny<0||ny>N) continue;
                    if(A[nx][ny]==0) continue;
                    ice++;
                }
                if(ice<3){
                    //주위에 얼음이 0인 칸이 3개이상이 아니면 얼음 감소시켜야하는데 탐색하면서 바로 감소시키면 안됨
                    iceminus.push_back(make_pair(i, j));
                    
                }
                
            }
        }
        
        //얼음양 -1 감소 시킬 곳 시키기
        for(int i=0; i<iceminus.size();i++){
            int x,y;
            x = iceminus[i].first;
            y = iceminus[i].second;
            A[x][y]--;
        }
        
        
 
    }
    
    // 남아있는 얼음 합
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            sum+=A[i][j];
        }
    }
    
    // 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
    // DFS

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            max_ice=0;
            //방문한 적이 없다면
            if(!visited[i][j]){
                
            }
        }
    }

    
}

