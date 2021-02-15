//백준 15661번

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int skill[21][21];
int ans;
vector<int> start;
bool start_yes;

vector<int> link;

int tempN;

void dfs(int num, int cnt, vector<int> link){
    if(cnt>=tempN){
        int start_skill=0;
        int link_skill=0;
        //start 팀 아닌 애들 link팀에 넣기
        for(int i=1; i<=N; i++){
            start_yes=false;
            for(int j=0; j<start.size(); j++){
                if(start[j]==i){
                    start_yes=true;
                    break;
                }
            }
            if(!start_yes) link.push_back(i);
        }
        
        for(int i=0; i<start.size(); i++){
            for(int j=0; j<start.size();j++){
                
                start_skill+=skill[start[i]][start[j]];
            }
        }
        
        for(int i=0; i<link.size();i++){
            for(int j=0; j<link.size();j++){
                
                link_skill+=skill[link[i]][link[j]];
            }
        }
        
        ans=min(ans,abs(link_skill-start_skill));
        
        return;
    }
    for(int i=num; i<=N; i++){
        start.push_back(i);
        vector<int> link;
        dfs(i+1,cnt+1,link);
        start.pop_back();
    }
}

int main(){
    ans=990;
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d",&skill[i][j]);
        }
    }
    vector<int> link;

    for(tempN=1; tempN<N; tempN++){
        dfs(1,0,link);
    }

    
    printf("%d",ans);

}
