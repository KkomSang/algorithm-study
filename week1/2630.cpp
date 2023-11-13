/*Divide-and-Conquer*/
#include <iostream>
using namespace std;

int white = 0, blue = 0;
int p[128][128];
void paper(int n, int s_1, int s_2){
    int cut = 0;
    for(int i = s_1; i < s_1 + n; i++){
        for(int k = s_2; k< s_2 + n; k++){
            if(p[s_1][s_2] != p[i][k]){
                cut = 1;
                break;
            }
        }
    }
    if(cut){
        paper(n/2, s_1, s_2);
        paper(n/2, s_1, s_2+n/2);
        paper(n/2, s_1+n/2, s_2);
        paper(n/2, s_1+n/2, s_2+n/2);
    }
    else{
        if(p[s_1][s_2] == 1){
        blue++;
        }
        else{
            white++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        for(int k = 0; k< n; k++){
            cin>>p[i][k];
        }
    }
    paper(n, 0, 0);
    cout<<white<<endl<<blue<<endl;
    return 0;
}