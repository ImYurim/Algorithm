//백준 1759번
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int L,C;
char list[16];
int con, vow;
vector<char> ans;


void dfs(int num, int cnt){
    if(cnt==L){
        vow=0;
        con=0;
        for(int i=0; i<ans.size();i++){
            if(ans[i]=='a'||ans[i]=='e'||ans[i]=='i'||ans[i]=='o'||ans[i]=='u'){
                vow++;
            }else{
                con++;
            }
        }
        if(con>=2&&vow>=1 ){
            for(int i=0; i<ans.size(); i++){
                printf("%c",ans[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=num; i<C; i++){
        ans.push_back(list[i]);
        dfs(i+1,cnt+1);
        ans.pop_back();
    }
    
    
}


int main(){

    scanf("%d %d",&L,&C);
    for(int i=0; i<C; i++){
        //띄어쓰기 있는 문자 입력받을 때 Space 입력 안받게 scanf 말고 cin 사용하기
        cin >> list[i];
    }
    sort(list,list+C);
    
    dfs(0,0);
}
