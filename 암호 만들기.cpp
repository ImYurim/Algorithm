//백준 1759번

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int L,C;
char list[16];


int main(){
    scanf("%d %d",&L,&C);
    for(int i=0; i<C; i++){
    //띄어쓰기 있는 문자 입력받을 때 Space 입력 안받게 scanf 말고 cin 사용하기
        cin >> list[i];
    }
    sort(list,list+C);
}
