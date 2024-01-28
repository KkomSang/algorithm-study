#include <iostream>
using namespace std;
int main(){
    long long s, sum = 0, i = 0, n = 0;
    cin>>s;
    while(sum+i+1 <= s){
        sum += ++i;
        n += 1;
    }
    cout<<n<<'\n';
    return 0;
}
