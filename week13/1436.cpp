#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, num = 666, cou = 1;
    string s;
    cin>>n;
    while(cou != n){
        num++;
        s = to_string(num);
        if(s.find("666")!=string::npos) {
            cou++;
        }
    }
    cout<<num<<'\n';
    return 0;
}