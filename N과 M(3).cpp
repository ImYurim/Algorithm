//백준 15651번
//숫자 중복 사용 가능한 수열
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N,M;
vector<int> arr;

bool visited[9];

void dfs(int cnt){
    if(cnt==M){
        for(int i=0; i<arr.size(); i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1; i<=N; i++){
        //if(visited[i])
        visited[i]=true;
        arr.push_back(i);
        dfs(cnt+1);
        visited[i]=false;
        arr.pop_back();
    }
}

int main(){
    scanf("%d %d",&N,&M);
    
    memset(visited, false, sizeof(visited));
    
    dfs(0);

}
