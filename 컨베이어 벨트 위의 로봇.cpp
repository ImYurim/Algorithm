#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int N,K;
int A[220];
int cnt=0;
int ans=0;
int Start;
int End;
bool visited[220]={false};
queue<int> robot;

void beltrotation();
void robotmove();


void beltrotation(){
    Start--;
    End--;
    if(Start<1)Start=2*N;
    if(End<1)End=2*N;
    

}

void robotmove(){
    for(int i = 0; i<robot.size(); i++){
        int loc = robot.front();
        
        visited[loc]=false;
        robot.pop();
        
        if(loc==End) continue;
        
        int nextloc = loc+1;
        if(nextloc>2*N) nextloc = 1;

        if(visited[nextloc]==false && A[nextloc]>=1){

            A[nextloc]--;
            if(A[nextloc]==0)cnt++;
            if(nextloc==End)continue;
            visited[nextloc]=true;
            robot.push(nextloc);

        }else{
            visited[loc]=true;
            robot.push(loc);

        }
    }
}

void makerobot(){
    if(visited[Start]==false && A[Start]>=1){
        visited[Start]=true;
        A[Start]--;
        robot.push(Start);
        if(A[Start]==0) cnt++;
    }
}

int main(){

    cin >> N >> K;
    for(int i = 1; i<=2*N; i++){
        cin >> A[i];
    }
    
    Start = 1;
    End = N;

    
    while(cnt<K){
        ans++;
        beltrotation();
        robotmove();
        makerobot();
       
    }

    
    
    cout << ans;
}
