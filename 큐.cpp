#include <iostream>
#include <queue>
#include <string>

using namespace std;


int N;
int push_num;
string order;
queue<int> numlist;



int main(){
    cin >> N;
    
    for(int i=0; i<N; i++){
        //string 변수에 키보드 입력 넣기. 띄어쓰기 전까지 변수에 넣어짐
        cin >> order;
        
        //string 변수와 문자열 비교는 == 연산자 이용
        if(order=="push"){
            cin >> push_num;
            numlist.push(push_num);
        }
        else if(order=="pop"){
            if(numlist.size()==0){
                cout << "-1";
                continue;
            }
            cout << numlist.front();
            numlist.pop();
        }
        else if(order == "size"){
            cout << numlist.size();
        }
        else if(order == "empty"){
            if(numlist.size()==0){
                cout << "1";
                
            }
            else{
                cout << "0";
            }
        }
        else if(order == "front"){
            if(numlist.size()==0){
                cout << "-1";
                continue;
            }
            cout << numlist.front();

        }
        else if(order == "back"){
            if(numlist.size()==0){
                cout << "-1";
                continue;
            }
            cout << numlist.back();

        }

    }

    

}
