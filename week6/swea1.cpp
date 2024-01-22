#include <iostream>
using namespace std;

int first(int n){ // n번째 행의 첫번째 값을 리턴하는 함수
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return n-1 + first(n-1);
    }
}

int line(int num){//num값이 몇번째 행인지 리턴하는 함수
    int i = 0;
    while(num >= first(i)){
        i++;
    }
    return i-1;
}
int row(int num){//num값이 한 행에서 몇번째 위치에 있는지 리턴하는 함수
    int fir = first(line(num));
    int i = 0;;
    while(num != fir + i){
        i++;
    }
    return i+1;
}
int oni(int s, int e){ //삼각김밥 개수를 리턴하는 함수
    int line_dis, row_dis;
    line_dis = line(s) - line(e);
    row_dis = row(s) - row(e);
    if(line_dis == 0 && row_dis == 0) return 0;
    else if(line_dis == 0) return abs(row_dis);
    else if(row_dis == 0) return abs(line_dis);
    else if(row_dis*line_dis < 0){
        return abs(line_dis) + abs(row_dis);
    }
    else{
        if(abs(row_dis) > abs(line_dis)){
            row_dis = abs(abs(row_dis)-abs(line_dis));
            return abs(line_dis) + row_dis;
        }
        else return abs(line_dis);
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC ,s, e, i = 1;
    cin>>TC;
    while(TC-->0){
        cin>>s>>e;
        cout<<"#"<<i++<<" "<<oni(s,e)<<'\n';
    }
    return 0;
}