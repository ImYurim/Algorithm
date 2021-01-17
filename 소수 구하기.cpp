//백준 1929번
#include <iostream>
#include <cstring>

long long M;
long long N;
int i;
int temp;

//bool ans[1000000]={true};
bool ans[1000000];


int main(){
    // 소수 이외의 숫자를 거르는 알고리즘 사용
    
    //배열 초기화
    memset(ans,true,sizeof(ans));
    scanf("%lld %lld",&M, &N);
    
    ans[1]=false;
    for(long long i=2; i<=N; i++){
        //2부터 하나씩 기준 숫자가 됨. 예1-1) i가 5일 때
        if(ans[i]){
            for(long long j=2*i; j<=N; j+=i){
                //예1-2) 5의 배수는 소수가 아니므로 제거
                ans[j]=false;
            }
        }

    }

    for(long long i=M; i<=N; i++){
        if(ans[i]==true) printf("%lld\n",i);
    }
    
}




//시간초과->M N 범위가 1,000,000 까지라 그럼
//숫자 범위가 클 때는 입력 받을 때마다 답을 구하는 것보다 Dynamic 으로 풀어야 함
// #include <iostream>
// long long M;
// long long N;
// int i;
// int temp;



// int main(){
//     scanf("%lld %lld",&M,&N);
    
//     for(long long j=M; j<=N; j++){
//         temp=0;
//         if(j==1)continue;
        
//         for(i=1; i<=j/2; i++){
//             if(j%i==0){
//                 temp++;
//             }
//         }
        
//         if(temp==1){
//             printf("%lld\n",j);
//         }

        
//     }
    

// }

