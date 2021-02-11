//백준 14501번
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int tp[17][2];
int ans;
int temp;
//이건 없어도됨
vector<int> d;

//순서가 있고 중복 비허용 dfs
void dfs(int date){
    if(date>N){
        ans=max(temp,ans);
        return;
    }
    //순서 있음
    for(int i=date; i<=N; i++){
        if(i+tp[i][0]-1>N) {
            dfs(i+tp[i][0]);

            continue;
            
        }
        
            
        temp+=tp[i][1];
        d.push_back(i);
        if(tp[i][0]==1)dfs(i+1);
        else{
            dfs(i+tp[i][0]);
        }
        temp-=tp[i][1];
        d.pop_back();
    }
}

int main(){
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        scanf("%d %d",&tp[i][0],&tp[i][1]);
    }
    ans=0;
    temp=0;
    dfs(1);
    
    printf("%d",ans);
}

