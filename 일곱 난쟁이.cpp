#include <iostream>
#include <algorithm>
using namespace std;

int dwarf[10];
int total;

//9명 중 2명을 골라 9명 키에서 2명의 키를 뺏을 때 100이 되는지 확인
int findstranger(int *dwarf){
    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if(total-dwarf[i]-dwarf[j]==100){
                dwarf[i]=-1;
                dwarf[j]=-1;
                
                return 0;
            }
        }
    }
    return -1;
}

int main(){
    total=0;
    for(int i=0; i<9; i++){
        scanf("%d",&dwarf[i]);
        total+=dwarf[i];
    }
    
    sort(dwarf,dwarf+9);
    
    findstranger(dwarf);
    
    //-1인 애들 앞으로 오게
    sort(dwarf,dwarf+9);
    
    //미리 sort하면 for문 안에 if문 넣어서 dwarf[i]==-1인가 확인 안해도됨
    for(int i=2; i<9; i++){
        printf("%d\n",dwarf[i]);
    }
    
}
