#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int R,C,T;
int map[51][51];
int c_map[51][51];
pair <int,int> cleaner[2];
//왼 위 오 아래
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void Input(){
    cin >> R >> C >> T;
    int idx=0;
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cin >> map[i][j];
            if(map[i][j]==-1){
                cleaner[idx].first = i;
                cleaner[idx].second = j;
                idx++;
            }
        }
    }
    
}
//A를 B에 복제
void copy(int A[51][51], int B[51][51]){
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            B[i][j]=A[i][j];
        }
    }
}

void dustspread(){
    copy(map,c_map);
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(map[i][j]!=0 && map[i][j] != -1){
                int cnt=0;
                int dust = map[i][j]/5;
                for(int m=0; m<4; m++){
                    int nx = i + dx[m];
                    int ny = j + dy[m];
                    if(nx>=0 && nx<R && ny>=0 && ny<C){
                        if(map[nx][ny]!=-1){
                            cnt++;
                            c_map[nx][ny]+=dust;
                        }
                    }
                    
                }
                c_map[i][j]-=dust*cnt;
            }

        }
    }
    copy(c_map,map);
}

void dustiteration(){
    
    for(int i = cleaner[0].first-1; i>0; i--){
        map[i][0]=map[i-1][0];
    }
    for(int j = 0 ; j<C-1; j++){
        map[0][j]=map[0][j+1];
    }
    for(int i = 1; i<=cleaner[0].first; i++){
        map[i-1][C-1]=map[i][C-1];
    }
    for(int j = C-1; j>1; j--){
        map[cleaner[0].first][j]=map[cleaner[0].first][j-1];
    }
    map[cleaner[0].first][1]=0;
    //아래
    for(int i = cleaner[1].first+1; i<R-1; i++){
        map[i][0]=map[i+1][0];
    }
    for(int j = 0; j<C-1; j++){
        map[R-1][j]=map[R-1][j+1];
    }
    for(int i = R-1; i>=cleaner[1].first; i--){
        map[i][C-1]=map[i-1][C-1];
    }
    for(int j = C-1; j>1; j--){
        map[cleaner[1].first][j]=map[cleaner[1].first][j-1];
    }
    map[cleaner[1].first][1]=0;
}

int dustsum(){
    int sum=0;
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(map[i][j]==-1)continue;
            sum += map[i][j];
        }
    }
    return sum;
}

int main(){
    Input();
 
    for(int t = T; t>0; t--){
        //미세먼지확산
        dustspread();
        //미세먼지순환
        dustiteration();
    }
    
    int ans = dustsum();
    cout<<ans;
    
}
