//백준 1107번

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int N,M;
bool mal[10];
int malnum;

int check(int num){
    if(num==0){
        if(mal[0])return 0 ;
        else return 1;
    }
    
    int len=0;
    while(num>0){
        //일의자리부터 고장난 버튼이 있는지 확인
        if(mal[num%10])return 0;
        num = num/10;
        len+=1;
    }
    return len;
}

int main(){
    //맨앞자리 숫자부터 가능한지 보고
    //가능하면 다음자리 숫자 보기
    //불가능하면
    //ex 4자리 수 4125 일때 4500보다 작은지 보기
    //작으면 3번째자리 숫자 -1 크면 3번째자리 숫자 +1 해서 가능한지 다시 확인
    //dfs로 풀어보려했음
    memset(mal, false, sizeof(mal));
    scanf("%d",&N);
    scanf("%d",&M);
    
    for(int i=0; i<M; i++){
        scanf("%d",&malnum);
        mal[malnum]=true;
    }
    
    //100번에서 + - 버튼만 눌러서 이동하는 횟수
    int result = abs(N-100);
    
    for(int i=0; i<=1000000; i++){
        //고장난 버튼이 하나라도 있으면 len는 0으로 return 됨
        int len = check(i);
        if(len>0){
            //plus 또는 minus 몇번 누르는지
            int press = abs(i-N);
            //숫자버튼 몇번누르는지 len + plus,minus 몇번 누르는지 press
            result = min(press+len,result);
        }
    }
    
    printf("%d\n",result);
    
    
}
