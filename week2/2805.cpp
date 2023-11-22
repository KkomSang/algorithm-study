#include <iostream>
using namespace std;
#include <algorithm>

/*시간초과!!!!!*/
/*int main(){
    int trees[1000000];
    int N, M, sum, result = 0, max;
    cin>>N>>M;
    for(int i = 0; i< N; i++){
        cin>>trees[i];
    }
    for(int i = 1; i< N; i++){
        if(result<trees[i]){
            result = trees[i];
        }
    }
    while(sum < M){
        sum = 0;
        result -= 1;
        for(int i = 0; i<N; i++){
            if(trees[i] > result){
                sum += trees[i] - result;
            }
        }
    }
    cout<<result<<endl;
    return 0;
}*/

/*이분탐색*/
int main(){
    int N,M,result=0,start,end,mid;
    long long int sum; //!!!!!!감사합니다 수키~
    cin>>N>>M;
    int trees[N];
    for(int i = 0; i< N; i++){
        cin>>trees[i];
    }
    sort(trees,trees+N);
    start = 0;
    end = trees[N-1];

    while(start<=end){
        sum = 0;
        mid = (start+end)/2;
        for(int i = 0; i< N; i++){
            if(trees[i]>mid){
                sum += trees[i]-mid;
            }
        }
        if(sum>=M){
            if(result<mid){
                result = mid;
            }
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    cout<<result<<endl;
    return 0;
}