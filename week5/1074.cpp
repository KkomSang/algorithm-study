#include <iostream>
#include <cmath>
using namespace std;
int N, r, c;
int z(int s_line, int s_row){
    int order = 0;
    int size = pow(2,N);
    while(size >= 1){
        int add = pow(size/2,2);
        if(r< s_line + size/2 && c<s_row + size/2){
            
        }
        else if(r< s_line + size/2 && c>=s_row + size/2 && c < s_row + size){
            order += add;
            s_row += size/2;
        }
        else if(r>=s_line + size/2 && r < s_line + size && c<s_row + size/2){
            order += add*2;
            s_line += size/2;
        }
        else{
            order += add*3;
            s_row += size/2;
            s_line += size/2;
        }
        size/=2;
    }
    return order;
}
int main(){
    cin>>N>>r>>c;
    int size = pow(2,N);
    cout<<z(0,0)<<'\n';
    return 0;
}