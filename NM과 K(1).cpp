//백준 18290번

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M,K;
int map[11][11];
bool visited[11][11];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int ans;
int temp;


void dfs(int cnt, int x, int y){
    if(cnt==K){
        ans=max(temp,ans);
        return;
    }
    //중복 없이 사전순
    for(int i=x; i<N; i++){
        for(int j=y; j<M; j++){
            if(visited[i][j])continue;
            if(visited[i-1][j]||visited[i][j-1]||visited[i][j+1]||visited[i+1][j])continue;
            visited[i][j]=true;
            temp+=map[i][j];
            if(j+1>=M)dfs(cnt+1,i+1,0);
            else{dfs(cnt+1,i,j+1);}
            visited[i][j]=false;
            temp-=map[i][j];
        }
    }
    
}

int main(){
    memset(visited, false, sizeof(visited));
    
    scanf("%d %d %d",&N,&M,&K);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            temp=0;
            dfs(0,i,j);
        }
    }
    printf("%d",ans);
}

















//틀렸습니다 - 이유: 대각선으로 인접한 케이스만 고려


//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//int N,M,K;
//int map[11][11];
//int dx[5]={0,-1,-1,1,1};
//int dy[5]={0,-1,1,-1,1};
//int nx,ny;
//bool visited[11][11];
//int ans;
//int temp;
//
//
//void dfs(int cnt, int x, int y){
//    if(cnt==K){
//        ans=max(temp,ans);
//        return;
//    }
//    
//    for(int i=0; i<5; i++){
//
//        nx=x+dx[i];
//        ny=y+dy[i];
//        if(x+dx[i]<0||y+dy[i]<0||x+dx[i]>=N||y+dy[i]>=N)continue;
//        if(visited[x+dx[i]][y+dy[i]])continue;
//        visited[x+dx[i]][y+dy[i]]=true;
// 
//        temp+=map[x+dx[i]][y+dy[i]];
// 
//        dfs(cnt+1,x+dx[i],y+dy[i]);
//        visited[x+dx[i]][y+dy[i]]=false;
//
//        temp-=map[x+dx[i]][y+dy[i]];
//    }
//}
//
//int main(){
//    memset(visited, false, sizeof(visited));
//    
//    scanf("%d %d %d",&N,&M,&K);
//    
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            scanf("%d",&map[i][j]);
//        }
//    }
//    
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            temp=0;
//            dfs(0,i,j);
//        }
//    }
//    printf("%d",ans);
//}
