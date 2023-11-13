/*DP*/
#include <iostream>
using namespace std;


int main(){
    int a[11] = {1, 2, 4};
    int n;
    for(int i = 3; i<11; i++){
        a[i] = a[i-1] + a[i-2] + a[i-3];
    }
    cin>>n;
    for(int i = 0; i<n; i++){
        int input;
        cin>>input;
        cout<<a[input-1]<<endl;
    }
    return 0;
}