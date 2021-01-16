//백준 1978번

#include <iostream>
int N;
int ans;
int num;
int i;
int temp;


int main(){
    scanf("%d",&N);
    while(N--){
        scanf("%d",&num);
        temp=0;
        
        if(num==1)continue;

        for(i=1; i<=num/2; i++){
            if(num%i==0){
                temp++;
            }
        }
        
        if(temp==1){
            ans++;
        }


    }
    printf("%d",ans);
}
