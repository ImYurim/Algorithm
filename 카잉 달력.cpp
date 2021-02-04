//백준 6064번

#include <iostream>

int T;
int M,N;
int x,y;
int year;
int ans;
int range;

int gcd(int m, int n){
    int temp;
    while(n!=0){
        temp = m%n;
        m=n;
        n=temp;
    }
    return m;
}

int lcd (int m, int n){
    return (m*n)/gcd(m,n);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d",&M,&N,&x,&y);
        ans=0;
        
        range = lcd(M,N);
        for(int i=x; i<=range; i+=M){
            if((i-1)%N+1==y){
                ans=i;
                break;
            }
        }
        if(ans!=0)printf("%d\n",ans);
        else printf("-1\n");


    }
    
}




//시간초과 M N x y가 40000 40000 이면 16000000000 만큼 반복문 돌아야하므로 시간초과
//#include <iostream>

//int T;
//int M,N;
//int x,y;
//int year;
//int ans;
//
//
//int main(){
//    scanf("%d",&T);
//    while(T--){
//        scanf("%d %d %d %d",&M,&N,&x,&y);
//        year=1;
//        while(!((year-1)%M+1==M && (year-1)%N+1==N)){
//            year++;
//        }
//
//        
//        ans=1;
//        while(!((ans-1)%M+1==x && (ans-1)%N+1==y) && (ans<=year)){
//            ans++;
//        }
//        
//        if(ans-1==year){
//            printf("-1\n");
//        }
//        else{
//            printf("%d\n",ans);
//
//        }
//
//
//    }
//}
