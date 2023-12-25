/*스택*/
#include <iostream>
#include <stack>
using namespace std;
stack<char> s;
int main(){
    int n;
    cin>>n;
    cin.ignore(); //입력 버퍼 비우기(->버퍼에 남아있는 개행문자 제거)
    string str;
    for(int i = 0; i< n; i++){
        getline(cin,str);
        for(int k = 0; k< str.length(); k++){
            if(str[k] != ' '){
                s.push(str[k]);
            }
            else{
                while(!s.empty()){
                    cout<<s.top();
                    s.pop();
                }
                cout<<" ";
            }
        }
        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}