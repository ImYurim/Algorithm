//백준 18290번
//백준에서 실패  
//https://qkrwlgus5832.tistory.com/48 
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
int nx,ny;
bool pass=false;


void dfs(int cnt, int x, int y){
    if(cnt==K){
        ans=max(temp,ans);
        return;
    }
    //중복 없이 사전순
    for(int i=x; i<N; i++){
        for(int j=y; j<M; j++){
            if(visited[i][j])continue;
            pass=false;
            for(int k=0; k<4; k++){
                nx = i+dx[k];
                ny = j+dy[k];
                
                if(nx<0||nx>=N||ny<0||ny>=M)continue;
                
                if(visited[nx][ny])pass=true;
            }
            
            if(pass)continue;
            
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












//맞았습니다 나오는 코드랑 똑같이 해봄 
//틀렸습니다 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M,K;
int map[11][11];
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int ans;


void dfs(int cnt, int index, int value, bool visited[11][11]){
    if(cnt==K){
        ans=max(value,ans);
        return;
    }
    //중복 없이 사전순
    for(int i=index; i<N*M; i++){
        int ii=i/M;
        int jj=i%M;

        
        bool pass=false;
        for(int k=0; k<4; k++){
            int nx = ii+dir[k][0];
            int ny = jj+dir[k][1];
            
            if(nx<0||nx>=N||ny<0||ny>=M)continue;
            
            if(visited[nx][ny])pass=true;
            
        }
        
        if(pass)continue;
        
        if(visited[ii][jj])continue;
        visited[ii][jj]=true;
        
        dfs(cnt+1, index+1, value+map[ii][jj],visited);
        
        visited[ii][jj]=false;
    }
    
}

int main(){
    bool visited[11][11];
    
    memset(visited, false, sizeof(visited));
    
    scanf("%d %d %d",&N,&M,&K);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d",&map[i][j]);
        }
    }

    dfs(0,0,0,visited);
    
    printf("%d",ans);
}




//답이 틀리게 나 - 이유: 대각선으로 인접한 케이스만 고려


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
