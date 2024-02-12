#include <iostream>
#include <queue>
using namespace std;
int m,n,h, day = -1;
int tomato[100][100][100] = {0};
int dm[] = {1,-1,0,0,0,0};
int dn[] = {0,0,1,-1,0,0};
int dh[] = {0,0,0,0,1,-1};
queue<pair<pair<int,int>, int> > q;
void bfs(){
    while(!q.empty()){
        int size = q.size();
        day++;
        for(int j = 0; j<size; j++){
            int hh = q.front().first.first;
            int nn = q.front().first.second;
            int mm = q.front().second;
            q.pop();
            for(int i= 0; i<6; i++){
                int next_m = mm + dm[i];
                int next_n = nn + dn[i];
                int next_h = hh + dh[i];
                if(next_m>=0 && next_n>=0 && next_h >=0 && next_m<m && next_n<n && next_h<h){
                    if(tomato[next_h][next_n][next_m] == 0){
                        tomato[next_h][next_n][next_m] = 1;
                        q.push(make_pair(make_pair(next_h,next_n),next_m));
                    }
                }
            }
        }
    }
}

int check(){
    for(int i = 0; i<h; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                if(tomato[i][j][k] == 0){
                    return -1;
                }
            }
        }
    }
    return 1;
}
int main(){
    cin>>m>>n>>h;
    for(int i = 0; i<h; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                cin>>tomato[i][j][k];
                if(tomato[i][j][k] == 1){
                    q.push(make_pair(make_pair(i,j),k));
                }
            }
        }
    }
    bfs();
    if(check() == -1) cout<<-1<<'\n';
    else if(check() == 1) cout<<day<<'\n';
    return 0;
}