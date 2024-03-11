#include <iostream>
#include <vector>
using namespace std;
/* dfs */
/*
vector<int > v[100];
int n;
bool visited[101] = {false};
void init(){
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
}
void dfs(int a){
    for(int i = 0; i<v[a].size(); i++){
        if(!visited[v[a][i]]){
            visited[v[a][i]] = true;
            dfs(v[a][i]);
        }
    }
}
int main(){
    int con;
    cin>>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>con;
            if(con){//연결되어 있으면 (1이면)
                v[i].push_back(j);
            }
        }
    }
    for(int i = 0; i<n; i++){
        init();
        dfs(i);
        for(int j = 0; j<n;j++){
            cout<<visited[j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
*/
/*플로이드-와샬*/
int g[101][101] = {0};
int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>g[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                if(g[j][i] && g[i][k]){
                    g[j][k] = 1;
                }
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<g[i][j]<<" ";
        }
        cout<<'\n';
    }
}