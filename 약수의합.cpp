//백준 17425번
#include <iostream>

int T;
int N;
int ans[1000000]={0};


int main(){
    ans[1]=1;
    //N이 1~1000000 중 나오므로 N이 각 숫자일 때 답이 뭔지 계산해서 배열에 넣음
    for(int i=2; i<=1000000; i++){
        for(int j=1; j<=i; j++){
            if(i%j==0){
                ans[i]+=j;
            }
        }
        //누적 값을 
        ans[i]+=ans[i-1];
    }

    
    //테스트 케이스 몇번
    scanf("%d", &T);
    while(T--){
        scanf("%d",&N);
        printf("%d\n",ans[N]);
    }

}





//시간초과
//
//#include <iostream>
//
//int T;
//int N;
//int ans;
//
//
//int main(){
//    scanf("%d",&T);
//    for(int t=0; t<T; t++){
//        scanf("%d",&N);
//        ans=0;
//        
//        for(int j=1; j<=N; j++){
//            for(int i=1; i<=j; i++){
//                if(j%i==0){
//                    ans+=i;
//                }
//            }
//            
//        }
//        printf("%d\n",ans);
//    }
//
//}

