/*dfs*/
#include <iostream>
using namespace std;

int visited[101] = {0};
int mat[101][101] = {0};
int computer;
int count1;

void dfs(int v){ 
    visited[v] = 1; 
    for(int i = 1; i<=computer; i++){
        if(visited[i] == 0 && mat[v][i] == 1){ 
            count1 += 1;
            dfs(i);
        }
    }
}

int main(){
    int pair;
    cin>>computer>>pair;
    for(int i = 0; i<pair; i++){
        int x, y;
        cin>>x>>y;
        mat[x][y] = mat[y][x] = 1;
    }
    dfs(1);
    cout<<count1;
    return 0;
}