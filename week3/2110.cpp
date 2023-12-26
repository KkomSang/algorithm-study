/*이분탐색*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200000
int house[MAX];
int main(){
    int n, c, max = 0, router, min = 1000000000;
    int start, end, mid;
    int min_d = 0;
    cin>>n>>c;
    for(int i = 0; i<n; i++){
        cin>>house[i];
        if(house[i]>max){
            max = house[i];
        }
        if(house[i]<min){
            min = house[i];
        }
    }
    start = 1; // 최소 거리
    end = max-min; //최대 거리
    sort(house,house+n);
     while(start<=end){
        router = 1;
        mid = (start+end)/2;
        int pre = house[0];
        for(int i = 1; i<n; i++){ 
            if(house[i] - pre >= mid){
                router += 1;
                pre = house[i];
            }
        }
        if(router >= c){ // 설치 공유기 개수가 초과했을 때->거리 늘리기
            if(min_d<mid){
                min_d = mid;
            }
            start = mid + 1;
        }
        else{// 설치 공유기 개수 부족할 때 -> 거리 좁히기
            end = mid -1;
        }
    }
    cout<<min_d<<endl;
    return 0;
}