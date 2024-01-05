#include <iostream>
#include <numeric>
using namespace std;

int decryp(string a){
    if(a.compare("0001101") == 0) return 0;
    else if(a.compare("0011001") == 0) return 1;
    else if(a.compare("0010011") == 0) return 2;
    else if(a.compare("0111101") == 0) return 3;
    else if(a.compare("0100011") == 0) return 4;
    else if(a.compare("0110001") == 0) return 5;
    else if(a.compare("0101111") == 0) return 6;
    else if(a.compare("0111011") == 0) return 7;
    else if(a.compare("0110111") == 0) return 8;
    else if(a.compare("0001011") == 0) return 9;
    else return -1;

}
void solve(int k){
    int N, M, cn, cm, odd = 0, even = 0;
    char arr[51][101];
    char code[8][8];
    int result[8];
    int final;
    cin>>N>>M;
    for(int i = 0; i< N; i++){
        cin>>arr[i];
    }
    for(int i = 0; i< N; i++){
        for(int j = M-1; j>0; j--){
            if(arr[i][j] == '1'){
                cn = i, cm = j;
                i = N+1;
                break;
            }
        }
    }
    for(int i = 7; i>=0; i--){
        for(int j = 7; j>=0; j--){
            if(j == 7) {
                code[i][j] = '\0';
                continue ;
            }
            else code[i][j] = arr[cn][cm--];
        }
    }
    for(int i = 0; i<8; i++){
        result[i] = decryp(code[i]);
    }
    for(int i = 0; i< 8; i++){
        if(i%2 == 0) odd += result[i];
        else even += result[i];
    }
    if((odd*3+even)%10 == 0) final = accumulate(result, result+8, 0);
    else final = 0;
    cout<<"#"<<k<<" "<<final<<'\n';
}
int main(){
    int TC;
    cin>>TC;
    for(int i = 1; i<= TC; i++){
        solve(i);
    }
    return 0;
}