//백준 15652번
//숫자 중복 사용 가능한 수열
//사전 순
//N과 M(2) 응용 
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N,M;
vector<int> arr;

bool visited[9];

void dfs(int num, int cnt){
    if(cnt==M){
        for(int i=0; i<arr.size(); i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=num; i<=N; i++){
        //if(!visited[i])
        visited[i]=true;
        arr.push_back(i);
        dfs(i, cnt+1);
        visited[i]=false;
        arr.pop_back();
    }
}

int main(){
    scanf("%d %d",&N,&M);
    
    memset(visited, false, sizeof(visited));
    
    dfs(1,0);

}
