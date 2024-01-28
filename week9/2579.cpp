#include <iostream>
using namespace std;
int stair[301];
int maxP[301];
int n;
int main(){
    cin>>n;
    for(int i = 1; i<=n; i++) cin>>stair[i];
    for(int i = 1; i<=n; i++){
        if(i == 1) maxP[1] = stair[1];
        else if(i == 2) maxP[2] = stair[1] + stair[2];
        else if(i == 3) maxP[3] = max(stair[1],stair[2]) + stair[3];
        else maxP[i] = max(maxP[i-2],maxP[i-3]+stair[i-1]) + stair[i]; 
    }
    cout<<maxP[n]<<'\n';
    return 0;
}