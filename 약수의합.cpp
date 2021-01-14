//백준 17425번

#include <iostream>

int T;
int N;
int ans;


int main(){
    scanf("%d",&T);
    for(int t=0; t<T; t++){
        scanf("%d",&N);
        ans=0;
        
        for(int j=1; j<=N; j++){
            for(int i=1; i<=j; i++){
                if(j%i==0){
                    ans+=i;
                }
            }
            
        }
        printf("%d\n",ans);
    }

}
