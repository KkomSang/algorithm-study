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

    if(n%2==1){//n: 홀수
        min = loss[n-1];//마지막 값 저장
        n--;//마지막 값(가장 큰 수) 제외
        for(int i = 0; i<n/2; i++){
            //높은 값 + 낮은 값
            check = loss[i] + loss[n-1-i];
            if(check>min) min = check;
        }
    }
    else{//n:짝수
        for(int i = 0; i<n/2; i++){
            //높은 값 + 낮은 값
            check = loss[i] + loss[n-1-i];
            if(check>min) min = check;
        }
    }
    cout<<min<<'\n';
    return 0;
}