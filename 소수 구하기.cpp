//백준 1929번

//시간초과->M N 범위가 1,000,000 까지라 그럼
//숫자 범위가 클 때는 입력 받을 때마다 답을 구하는 것보다 Dynamic 으로 풀어야 함
#include <iostream>
long long M;
long long N;
int i;
int temp;



int main(){
    scanf("%lld %lld",&M,&N);
    
    for(long long j=M; j<=N; j++){
        temp=0;
        if(j==1)continue;
        
        for(i=1; i<=j/2; i++){
            if(j%i==0){
                temp++;
            }
        }
        
        if(temp==1){
            printf("%lld\n",j);
        }

        
    }
    

}

