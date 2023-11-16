/*bfs*/
//모르겠어요~!~!~~!! 다른 거 풀래용~~
#include <iostream>
#include <vector>
using namespace std;
#include <queue>
queue<pair<int,int>> q;
int n;
 
int visited[101][101] = {0};
char RGB[101][101];

void bfs(int x, int y){
    q.push({x,y});
    visited[x][y] = 1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 1; i<=n; i++){
            //if()
        }
    }
}

int main(){
    cin>>n;
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            cin>>RGB[i][j];
        }
    }
    return 0;
}