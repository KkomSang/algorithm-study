#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> loss;
int n;

int main(){
    long long l, min = 0, check;
    cin>>n;
    for(int i = 0; i<n; i++) {
        cin>>l;
        loss.push_back(l);
    }
    sort(loss.begin(),loss.end());
    if(n%2==1){//홀수
        min = loss[n-1];
        n--;
        for(int i = 0; i<n/2; i++){
            check = loss[i] + loss[n-1-i];
            if(check>min) min = check;
        }
    }
    else{
        for(int i = 0; i<n/2; i++){
            check = loss[i] + loss[n-1-i];
            if(check>min) min = check;
        }
    }
    cout<<min<<'\n';
    return 0;
}