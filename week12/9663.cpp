#include <iostream>
using namespace std;
int n, result = 0;
int col[15] = {0}; 
typedef struct node{
    int col;//열
    int row;//행
    node* left;
    node* right;
}node;
bool promising(int i){
    int k = 1;
    bool s = true;
    while(k<i && s){
        if(col[i]==col[k] || abs(col[i]-col[k]) ==abs(i-k)){
            s = false;
        }
        k++;
    }
    return s;
}

void queens(int i){//i번째 행
    if(promising(i)){
        if(i == n){
            result++;
        }
        else{
            for(int j = 1; j<=n; j++){
                col[i+1] = j;
                queens(i+1);
            }
        }
    }
}
int main(){
    cin>>n;
    queens(0);
    cout<<result<<'\n';
    return 0;
}