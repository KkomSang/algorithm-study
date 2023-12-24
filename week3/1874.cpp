#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int right1 = 1;
int count1 = 0;
int a = 0;
char ans[1000000];
int main(){
    int n;
    cin>>n;
    for(int i = 0; i< n; i++){
        int num;
        cin>>num;
        if(count1 < num){
            while(count1 < num){
                s.push(++count1);
                ans[a++] = '+';
            }
            s.pop();
            ans[a++] = '-';
        }
        else if(count1 == num){
            s.pop();
            ans[a++] = '-';
        }
        else{
            if(num == s.top()){
                s.pop();
                ans[a++] = '-';
            }
            else{
                right1 = 0;
            }
        }
    }
    if(right1 == 1){
        int k = 0;
        while(ans[k] != 0){
            cout<<ans[k++]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
