//백준 6588번

#include <iostream>
#include <cstring>

//소수 여부를 미리 배열에 true false로 저장해놓기

long long n;
long long a;
long long b;
bool ans;
bool f[1000000];


int main(){
    memset(f, true, sizeof(f));
    f[1]=false;
    for(int i=2; i<=1000000; i++){
        for(int j=2*i; j<=1000000; j+=i){
            f[j]=false;
        }
    }
    
    while(scanf("%lld",&n) && n!=0){
        ans=false;
        for(long long i=2; i<=n/2; i++){
            a=i;
            if(!f[a])continue;
            b=n-a;
            if(!f[b])continue;
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
