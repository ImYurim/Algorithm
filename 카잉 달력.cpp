//백준 6064번
//시간초과
#include <iostream>

int T;
int M,N;
int x,y;
int year;
int ans;


int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d",&M,&N,&x,&y);
        year=1;
        while(!((year-1)%M+1==M && (year-1)%N+1==N)){
            year++;
        }

        
        ans=1;
        while(!((ans-1)%M+1==x && (ans-1)%N+1==y) && (ans<=year)){
            ans++;
        }
        
        if(ans-1==year){
            printf("-1\n");
        }
        else{
            printf("%d\n",ans);

        }


    }
}
