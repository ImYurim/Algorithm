//백준 1037번

#include <iostream>
#include <algorithm>
using namespace std;

int cnt;
int num[1000000];
int ans;

int main(){
    scanf("%d",&cnt);
    for(int i=0; i<cnt; i++){
        scanf("%d",&num[i]);
    }
    sort(num,num+cnt);
    
    ans = num[0]*num[cnt-1];
    
    printf("%d",ans);
}
