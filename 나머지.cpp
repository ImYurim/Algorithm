//백준 10430번
//(A+B)%C는 ((A%C) + (B%C))%C 와 같고 
//(A×B)%C는 ((A%C) × (B%C))%C 와 같은 것을 이용
#include <iostream>

int A,B,C;

int main(){
    scanf("%d %d %d",&A,&B,&C);
    printf("%d\n", (A+B)%C);
    printf("%d\n",(A+B)%C);
    printf("%d\n",(A*B)%C);
    printf("%d",(A*B)%C);
}

//#include <iostream>
//
//int A,B,C;
//
//int main(){
//    scanf("%d %d %d",&A,&B,&C);
//    printf("%d\n", (A+B)%C);
//    printf("%d\n",((A%C) + (B%C))%C);
//    printf("%d\n",(A*B)%C);
//    printf("%d",((A%C) * (B%C))%C);
//}
