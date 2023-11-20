/*bfs*/
#include <iostream>
#include <vector>
using namespace std;
#include <queue>
queue<pair<int,int> > q;
int n;
 
int visited[101][101] = {0};
char RGB[101][101];
int xx[4] = {1,-1,0,0}; //아래, 위, 왼, 오
int yy[4] = {0,0,-1,1};
int count1 = 0;

void bfs(int x, int y){
    q.push(make_pair(x,y));
    visited[x][y] = 1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int next_x = x + xx[i];
            int next_y = y + yy[i];
            if(next_x>=0 && next_y>=0 && next_x<n && next_y<n){
                if(visited[next_x][next_y] == 0 && RGB[next_x][next_y] == RGB[x][y]){
                    visited[next_x][next_y] = 1;
                    q.push(make_pair(next_x,next_y));
                }
            }
        }
    }
}
void reset_rtog(){
    count1 = 0;
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            if(RGB[i][j] == 'R'){
                RGB[i][j] = 'G';
            }
        }
    }
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            visited[i][j] = 0;
        }
    }
    while(!q.empty()){
        q.pop();
    }
}

int main(){
    cin>>n;
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            cin>>RGB[i][j];
        }
    }
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            if(visited[i][j]){
                continue;
            }
            bfs(i,j);
            visited[i][j] = 1;
            count1++;
        }
    }
    cout << count1<<" ";
    reset_rtog();
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            if(visited[i][j]){
                continue;
            }
            bfs(i,j);
            visited[i][j] = 1;
            count1++;
        }
    }
    cout<<count1<<endl;
    return 0;
}