#include <iostream>
#include <queue>
using namespace std;

int N, M;
int maze[101][101];
int visited[101][101] ={0};
int dis[101][101];
queue<pair<int,int> > q;


void bfs(int x, int y){
    visited[x][y] = 1;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x+1<N && maze[x+1][y] == 1 && visited[x+1][y] == 0){
            visited[x+1][y] = 1;
            dis[x+1][y] = dis[x][y] + 1;
            q.push(make_pair(x+1,y));
        }
        if(x-1>=0 && maze[x-1][y] == 1 && visited[x-1][y] == 0){
            visited[x-1][y] = 1;
            dis[x-1][y] = dis[x][y] + 1;
            q.push(make_pair(x-1,y));
        }
        if(y+1<M && maze[x][y+1] == 1 && visited[x][y+1] == 0){
            visited[x][y+1] = 1;
            dis[x][y+1] = dis[x][y] + 1;
            q.push(make_pair(x,y+1));
        }
        if(y-1>=0 && maze[x][y-1] == 1 && visited[x][y-1] == 0){
            visited[x][y-1] = 1;
            dis[x][y-1] = dis[x][y] + 1;
            q.push(make_pair(x,y-1));
        }
    }
}


int main(){
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        string arr;
        cin>>arr;
        for(int j =0; j<M;j++){
            maze[i][j] = arr[j] - 48;
        }
    }     
    bfs(0,0);
    
    cout<<dis[N-1][M-1] +1<<endl;
    return 0;
}