//백준 1476번
#include <iostream>

int year;
int E;
int e;
int S;
int s;
int M;
int m;

int main(){
    scanf("%d %d %d", &E, &S, &M);
    year=0;
    e=0;
    s=0;
    m=0;
    while(1){
        if(e==E&&s==S&&m==M)break;
        year++;
        e++;
        if(e>15)e-=15;
        s++;
        if(s>28)s-=28;
        m++;
        if(m>19)m-=19;
    }
    printf("%d",year);
}

// #include <iostream>

// int year;
// int E;
// int e;
// int S;
// int s;
// int M;
// int m;

// int main(){
//     scanf("%d %d %d", &E, &S, &M);
//     year=1;
//     e=0;
//     s=0;
//     m=0;
//     while(!((year-1)%15+1==E&&(year-1)%28+1==S&&(year-1)%19+1==M)){
//         year++;

//     }
//     printf("%d",year);
// }
