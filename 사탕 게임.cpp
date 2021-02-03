//백준 3085번
//문자열 입력 부분 오류

#include <iostream>
//swap함수
#include <algorithm>
using namespace std;

char map[51][51];
int N;
int anscandy;
int tempcandy;


void maxcandy(){
    //가로
    for(int i = 0; i<N; i++){
        tempcandy=1;
        for(int j = 0; j<N-1; j++){
            if(map[i][j]!=map[i][j+1]){
                anscandy=max(anscandy,tempcandy);
                tempcandy=1;
            }else{
                tempcandy++;
            }
            anscandy=max(anscandy,tempcandy);
        }
        

    }
    //세로
    for(int j = 0; j<N; j++){
        tempcandy=1;
        for(int i = 0; i<N-1; i++){
            if(map[i][j]!=map[i+1][j]){
                anscandy=max(anscandy,tempcandy);
                tempcandy=1;
            }else{
                tempcandy++;
            }
            anscandy=max(anscandy,tempcandy);
        }
        


    }
    
}

int main(){
    anscandy=0;
    scanf("%d",&N);

    for(int i = 0; i<N; i++){

        scanf("%s",map[i]);
        
    }

    for(int i = 0; i<N; i++){
        //j의 범위가 N-2까지 인것 주의 맨마지막 행과 맨마지막 열은 비교대상이 없기 때문
        for(int j = 0; j<N-1; j++){
            //양옆
            if(map[i][j]!=map[i][j+1]){
                swap(map[i][j],map[i][j+1]);
                maxcandy();
                swap(map[i][j],map[i][j+1]);
            }
            //위아래
            if(map[i][j]!=map[i+1][j]){
                swap(map[i][j],map[i+1][j]);
                maxcandy();
                swap(map[i][j],map[i+1][j]);
            }

        }
    }
    cout << anscandy;
    
    
}


