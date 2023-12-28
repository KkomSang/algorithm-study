#include <iostream>
using namespace std;
int **mov;
void quad(int N, int s_line, int s_row){
    bool d1 = true, d2 = true, d3 = true, d4 = true;
    int check1 = mov[s_line][s_row], check2 = mov[s_line][s_row + N/2], 
    check3 = mov[s_line + N/2][s_row], check4 = mov[s_line + N/2][s_row + N/2];
    for(int i = s_line; i< s_line + N/2; i++){
        for(int j = s_row; j< s_row + N/2; j++){
            if(mov[i][j] != check1){
                check1 = -1;
                d1 = false;
            }
        }
    }
    for(int i = s_line; i< s_line + N/2; i++){
        for(int j = s_row + N/2; j< s_row + N; j++){
            if(mov[i][j] != check2){
                check2 = -1;
                d2 = false;
            }
        }
    }
    for(int i = s_line + N/2; i< s_line + N; i++){
        for(int j = s_row; j< s_row + N/2; j++){
            if(mov[i][j] != check3){
                check3 = -1;
                d3 = false;
            }
        }
    }
    for(int i = s_line + N/2; i< s_line + N; i++){
        for(int j = s_row + N/2; j< s_row + N; j++){
            if(mov[i][j] != check4){
                check4 = -1;
                d4 = false;
            }
        }
    }
    if(check1 == check2 && check2 == check3 && check3 == check4 && d1 && d2 && d3 && d4){
        cout<<check1;
        return ;
    }
    cout<<"(";
    if(check1 >= 0){
        cout<<check1;
    }
    else quad(N/2, s_line, s_row);

    if(check2 >= 0){
        cout<<check2;
    }
    else quad(N/2, s_line, s_row + N/2);

    if(check3 >= 0){
        cout<<check3;
    }
    else quad(N/2, s_line + N/2, s_row);

    if(check4 >= 0){
        cout<<check4;
    }
    else quad(N/2, s_line + N/2, s_row + N/2);
    cout<<")";
}
int main(){
    int N;
    cin>>N;
    mov = new int*[N];
    for(int i = 0; i < N; i++){
        mov[i] = new int[N];
    }
    for(int i = 0; i<N; i++){
        char arr[N];
        cin>>arr;
        for(int j = 0; j<N; j++){
            mov[i][j] = arr[j]-48;
        }
    }
    quad(N,0,0);
    cout<<"\n";
    return 0;
}