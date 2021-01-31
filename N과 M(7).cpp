//백준 15657번
//중복 허용, 사전 순  
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

void dfs(int cnt, int index){
    if(cnt==M){
        for(int i=0; i<arr.size(); i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    //i는 index부터 시작-> 앞 숫자보다 크기 위함(사전순 위함)
    for(int i=index; i<input.size(); i++){
//        if(visited[input[i]])continue;
        visited[input[i]]=true;
        arr.push_back(input[i]);
        //사전순이지만 중복 허용위해 -> 두번째 인자가 i+1이 아니라 i
        dfs(cnt+1,i);
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
