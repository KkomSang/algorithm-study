#include <iostream>
using namespace std;
int main(){
    int n, price[10001], dp[10001];
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>price[i];
    }
    price[0] = dp[0] = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            dp[i] = max(dp[i],dp[i-j]+price[j]);
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}