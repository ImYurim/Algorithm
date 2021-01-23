//백준 9095번
#include <iostream>

int T;
int n;
int ans[12];
int answer;

int solve(int n){
    if(n==1)return 1;
    if(n==2)return 2;
    if(n==3)return 4;
    
    return solve(n-1)+solve(n-2)+solve(n-3);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        answer=solve(n);
        printf("%d\n",answer);
    }
}
