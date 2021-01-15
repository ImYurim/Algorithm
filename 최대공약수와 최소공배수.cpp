//백준 2609번

#include <iostream>
#include <algorithm>
using namespace std;

int n1;
int n2;
int range;
int f=2;
int l=1;
int m=1;




int main(){
    scanf("%d %d",&n1, &n2);
    range = min(n1,n2);
    
    //최대공약수
    while(f<=range){
        if(n1%f==0 && n2%f==0){
            l*=f;
            n1/=f;
            n2/=f;
            
        }else{
            f++;
        }
    }

    printf("%d\n",l);
    //최소공배수
    m=l*n1*n2;
    printf("%d",m);
}
