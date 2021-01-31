//백준 15654번
//불연속적인 수들의 수열


#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int i_num;
int turn;
vector<int> input;
vector<int> arr;

bool visited[10001];

void dfs(int cnt){
    if(cnt==M){
        for(int i=0; i<arr.size(); i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0; i<input.size(); i++){
        if(visited[input[i]])continue;
        visited[input[i]]=true;
        arr.push_back(input[i]);
        dfs(cnt+1);
        visited[input[i]]=false;
        arr.pop_back();
    }
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0; i<N; i++){
        scanf("%d",&i_num);
        input.push_back(i_num);
    }
    sort(input.begin(),input.end());
    
    memset(visited, false, sizeof(visited));
    
    dfs(0);

}
