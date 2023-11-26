#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int *card;
int *num;

int upper(int target){
    int start = 0, end = N, mid;
    while(start<end){
        mid = (start+end)/2;
        if(card[mid] > target)
            end = mid;
        else 
            start = mid + 1;
    }
    return end;
}

int lower(int target){
    int start = 0, end = N, mid;
    while(start<end){
        mid = (start+end)/2;
        if(card[mid] >= target)
            end = mid;
        else 
            start = mid + 1;
    }
    return end;
}


int main(){
    cin>>N;
    card = new int[N];
    for(int i = 0; i< N; i++){
        cin>>card[i];
    }
    cin>>M;
    num = new int[M];
    for(int i = 0; i< M; i++){
        cin>>num[i];
    }
    sort(card,card+N);
    for(int i = 0; i<M; i++){
       //cout<<upper_bound(card,card+N,num[i]) - lower_bound(card,card+N,num[i])<<" ";
       cout<<upper(num[i])-lower(num[i])<<" ";
    }
    cout<<endl;
    delete[] card;
    delete[] num;
    return 0;
}