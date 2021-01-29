//백준 15650번

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N,M;
vector<int> arr;

bool visited[9];

void dfs(int cnt,int num){
    if(cnt==M){
        for(int i=0; i<arr.size(); i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=num; i<=N; i++){
        if(visited[i])continue;
        visited[i]=true;
        arr.push_back(i);
        dfs(cnt+1,i+1);
        visited[i]=false;
        arr.pop_back();
    }
}

int main(){
    scanf("%d %d",&N,&M);
    
    memset(visited, false, sizeof(visited));
    
    dfs(0,1);

}
