/**/
#include <iostream>
using namespace std;

int main(){
    int N, bag = 0;
    cin>>N;
    while(N>0){
        if(N%5 == 0){
            bag += N/5;
            break;
        }
        else{
            N -= 3;
            if(N<0){
                cout<<-1<<endl;
                return 0;
            }
            else{
            bag += 1;
            }
        }
    }
    cout<<bag<<endl;
    return 0;
}