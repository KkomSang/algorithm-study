#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
int n,m,res;
bool visited[1001] = {false};
int dist[1001][1001] = {0};
vector<pair<int,int> >g[1001];
void init(){
    for(int i = 0; i< 1001; i++){
        visited[i] = false;
    }
}
void dfs(int s, int e, int d){
    visited[s] = 1;
    if(s==e){
        res = d;
        return ;
    }
    for(int i = 0; i<g[s].size(); i++){
        int cost = d + g[s][i].second;
        int next = g[s][i].first;
        if(!visited[next]){ 
            visited[next] = true;
            dfs(next,e,cost);
        }
    } 
}
int main(){
    cin>>n>>m;
    for(int i =0; i<n-1; i++){
        int r,c,d;
        cin>>r>>c>>d;
        g[r].push_back(make_pair(c,d));
        g[c].push_back(make_pair(r,d));
    }
    for(int i = 0; i<m; i++){
        //d = 0;
        init();
        int n1,n2;
        cin>>n1>>n2;
        dfs(n1,n2,0);
        cout<<res<<'\n';
    }
    return 0;
}