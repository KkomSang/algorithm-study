#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int TC = 1;
    while(TC < 11){
        int height[1000];
        int N, cou = 0;
        cin>>N;
        for(int i = 0; i< N; i++){
            cin>>height[i];
        }
        for(int i = 2; i< N-1; i++){
            int right, left, compare;
            left = max(height[i-2],height[i-1]);
            right = max(height[i+1],height[i+2]);
            if(height[i] > left && height[i] > right){
                compare = max(left, right);
                cou += height[i] - compare;
            }
        }
        cout<<"#"<<TC<<" "<<cou<<'\n';
        TC += 1;
    }

    return 0;
}