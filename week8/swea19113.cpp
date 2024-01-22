#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int tc, item;
    cin>>tc;
    for(int t = 1; t<=tc; t++){
        int d = 0;
        cin>>item;
        long price[200] = {0};
        long discount[100] = {0};
        for(int i = 0; i< 2*item; i++){
            cin>>price[i];
        }
        for(int i = 0; i< 2*item; i++){
            for(int j = 0; j<2*item; j++){
                if(i >= j || price[i] == -1 || price[j] == -1) continue;
                if(price[i] == price[j]*0.75){
                    discount[d++] = price[i];
                    price[i] = -1;
                    price[j] = -1;
                }
            }
        }
        sort(discount, discount+item);
        cout<<"#"<<t<<" ";
        for(int i = 0; i<item; i++){
            cout<<discount[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
