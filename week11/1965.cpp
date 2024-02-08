#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int bi(vector<int> box, int n) {
    int lis[1000] = {0};
    int start = 0;
    lis[start++] = box[0];
    for(int i = 1; i < n; i++) {
        if(lis[start-1] < box[i]) {
            lis[start++] = box[i];
        } else {
            int *p = lower_bound(lis, lis+start, box[i]);
            *p = box[i];
        }
    }
    return start;
}

int main(){
    int n;
    vector<int> box;
    cin>>n;
    for(int i = 0; i <n; i++){
        int size;
        cin>>size;
        box.push_back(size);
    }
    /*dp*/
    // int dp[1000] = {0};
    // dp[0] = 1;
    // for(int i = 1; i<n; i++){
    //     for(int j = 0; j<i; j++){
    //         if(box[j] < box[i]) dp[i] = max(dp[i], dp[j] + 1);            
    //         if(dp[i] == 0) dp[i] = 1;
    //     }
    // }
    //cout<<*max_element(dp,dp+n)<<"\n";

    /*이분탐색*/
    cout<<bi(box,n)<<'\n';
    return 0;
}