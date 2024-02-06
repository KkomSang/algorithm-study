#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main(){
    int n, k, result = 0;
    long height[300000], cost[300000];
    //memset(height,1000000001, sizeof(height));
    //memset(cost,1000000001, sizeof(cost));
    cin>>n>>k;
    for(int i = 0; i<n; i++){
        cin>>height[i];
    }
    sort(height,height+n);
    for(int i = 0; i<n-1; i++){
        cost[i] = height[i+1] - height[i];
    }
    sort(cost, cost+n);
    // for(int i = 0; i<n; i++){
    //     cout<<cost[i]<<" ";
    // }
    // cout<<'\n';
    for(int i = 0; i<n-k; i++){
        result += cost[i];
    }
    cout<<result<<'\n';
    return 0;
}