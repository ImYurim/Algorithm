//백준 15655번
//불연속적인 수들의 수열
//숫자 사전순, 중복 출력 x -> dfs 인자 2개 (하나는 몇번째 숫자인지, 하나는 어떤 숫자 기준인지)
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

void dfs(int cnt,int index){
    if(cnt==M){
        for(int i=0; i<arr.size(); i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=index; i<input.size(); i++){
        if(visited[input[i]])continue;
        visited[input[i]]=true;
        arr.push_back(input[i]);
        dfs(cnt+1,i+1);
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
    
    dfs(0,0);

}
