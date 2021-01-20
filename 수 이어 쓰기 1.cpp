//백준 1748번
//백준제출오류

#include <iostream>
#include <cmath>
using namespace std;

long long N;
int ans;
int N_num;
int each_num[10];

int root;


int main(){
    //자리수 개수마다 몇개 숫자 있는지 배열에 저장
    for(int i=1; i<=9; i++){
        each_num[i]=(pow(10,i)-1)-(pow(10,i-1)-1);
    }
    
    scanf("%lld",&N);
    ans=0;
    //입력된 수의 자리수 구하기 N_num
    for(int i=1; i<=9; i++){
        root=N/(pow(10,i-1));
        if(root!=0)continue;
        N_num=i-1;
        break;
    }
    
    //N_num-1
    for(int i=1; i<N_num; i++){
        ans+=each_num[i]*i;
    }
    ans += (N-pow(10,N_num-1)+1 )* N_num;
     
    printf("%d",ans);
                    
}

