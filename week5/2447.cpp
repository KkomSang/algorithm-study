#include <iostream>
using namespace std;

void star(int n, int i, int j){
    if((i/n)%3 == 1 && (j/n)%3 == 1){
        cout<<" ";
    }
    else{
        if(n == 1){
            cout<<"*";
        }
        else star(n/3,i,j);
    }
}

int main(){
    int N;
    cin>>N;
    for(int i = 0; i< N; i++){
        for(int j = 0; j<N; j++){
            star(N,i,j);
        }
        cout<<'\n';
    }
    return 0;
}