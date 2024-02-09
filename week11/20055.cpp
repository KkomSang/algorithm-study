#include <iostream>
#include <deque>
using namespace std;
deque<int> con;
deque<bool> robot;
int n,k;

void rotation(){
    con.push_front(con.back());
    con.pop_back();

    robot.push_front(robot.back());
    robot.pop_back();

    robot[n-1] = false;
}

void move_robot(){
    for(int i = n-2; i>= 0; i--){
        if(robot[i] && !robot[i+1] && con[i+1] >= 1){
            robot[i] = false;
            robot[i+1] = true;
            con[i+1]--;
        }
        robot[n-1] = false;
    }
}

void put_robot(){
    if(!robot[0] && con[0] >= 1){
        robot[0] = true;
        con[0]--;
    }
}

int zero_check(){
    int zero = 0;
    for(int i = 0; i<2*n; i++){
        if(con[i] == 0) zero++;
    }
    return zero;
}
int main(){
    int stage = 0;
    cin>>n>>k;
    for(int i = 0; i<2*n; i++){
        int a;
        cin>>a;
        con.push_back(a);
        robot.push_back(false);
    }
    while(zero_check() < k){
        rotation();
        move_robot();
        put_robot();
        stage++;
    }
    cout<<stage<<'\n';
    return 0;
}