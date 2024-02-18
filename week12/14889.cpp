#include <iostream>
#include <vector>
using namespace std;
int n, dif = 987654321;
vector<vector<int> > ab;
int com[10]={0}; // 조합
bool check[20] = {false};
void dfs(int depth, int start){
    if(depth == n/2){//조합이 n/2명(한 팀의 구성원 수)만큼 구성됨
        int t1 = 0, t2 = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0;j<n; j++){
                if(check[i] == true && check[j] == true) t1 += ab[i][j];
                if(check[i] == false && check[j] == false)t2 += ab[i][j];
            }
        }
        if(dif > abs(t1-t2)) dif = abs(t1-t2);// 각 팀의 최소 능력치 차이 갱신
    }
    else{ // 아직 조합이 n/2명(한 팀의 구성원 수)만큼 다 구성되지 않음
        for(int i = start; i<n; i++){
            check[i] = true;
            com[depth] = i;
            dfs(depth+1, i+1);// 중복을 허용하지 않으므로 i+1
            check[i] = false;
        }
    }
}
int main(){
    cin>>n;
    for(int i = 0; i<n; i++){
        vector<int> v;
        for(int j = 0; j<n; j++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        ab.push_back(v);
    }
    dfs(0,0);
    cout<<dif<<'\n';
    return 0;
}