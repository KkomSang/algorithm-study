#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n,m,v;
int visited[1001]; // 방문여부 체크
int mat[1001][1001]; // 인접행렬
queue<int> q;
stack<int> st;

void reset(){
    for(int i = 0;i<1001;i++){
        visited[i] = 0;
    }
}

/*재귀를 이용한 dfs 구현*/
// void dfs(int v){ 
//     cout<<v<<" ";
//     visited[v] = 1; 
//     for(int i = 1; i<=n; i++){
//         if(visited[i] == 0 && mat[v][i] == 1){ 
//             dfs(i);
//         }
//     }
// }

/*스택을 이용한 dfs 구현*/
void dfs(int v){
    st.push(v);
    while(!st.empty()){
        v = st.top();
        st.pop();
        if(visited[v] == 0){
            cout<<v<<" ";
        }
        visited[v] = 1;
        for(int i =n; i>0; i--){
            if(visited[i] == 0 && mat[v][i] == 1){
                st.push(i);
            }
        }

    }
}

void bfs(int v){
    q.push(v);
    visited[v] = 1;
    while(!q.empty()){
        v = q.front();
        q.pop();
        cout<<v<<" ";
        for(int i=1; i<=n; i++){
            if(visited[i] == 0 && mat[v][i] == 1){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
int main(){
    int a, b;
    cin >> n >> m>> v;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        mat[a][b] = mat[b][a] = 1;
    }
    dfs(v);
    cout<<endl;
    reset();
    bfs(v);
    cout<<endl;
    return 0;
}
