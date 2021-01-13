//백준 4375

#include <iostream>

int e, num, count;

int main(){

    while(scanf("%d",&e)!=EOF){
        num=1;
        count=1;
        
        while(1){
            
            if(num%e==0){
                printf("%d\n",count);
                break;
            }
            
            num = ((num * 10)+ 1)%e;
            count++;
        }

        
    }
    
}
