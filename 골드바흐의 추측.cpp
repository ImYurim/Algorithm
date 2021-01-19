#include <iostream>
#include <cstring>

//소수 여부를 미리 배열에 true false로 저장해놓기

long long n;
long long a;
long long b;
//답이 있는지 없는지
bool ans;
//각 숫자가 소수인지
bool f[1000000];


int main(){
    //1부터 1000000 까지 숫자들이 소수인지 판별
    //소수 구하기 문제의 알고리즘 사용
    memset(f, true, sizeof(f));
    f[1]=false;
    for(int i=2; i<=1000000; i++){
        for(int j=2*i; j<=1000000; j+=i){
            f[j]=false;
        }
    }
    
    //입력받은 숫자가 0이 아닐때까지만
    while(scanf("%lld",&n) && n!=0){
        ans=false;
        //입력받은 숫자의 반절까지만 살펴보면됨 어차피 반절 이후에는 중복이니까
        //ex)3+5 는 5+3과 같음 그리고 뒷 숫자가 더 커야함 (조건)
        for(long long i=2; i<=n/2; i++){
            a=i;
            //a가 소수가 맞나
            if(!f[a])continue;
            //a가 소수가 맞으면 n-a 해서 b를 구해줌
            b=n-a;
            //b가 소수가 맞나
            if(!f[b])continue;
            //b가 소수가 맞으면 답이 있다.
            ans=true;
            break;
        }
        if(ans){
            printf("%lld = %lld + %lld\n",n,a,b);
        }else{
            printf("Goldbach's conjecture is wrong.\n");
        }

    }

}
