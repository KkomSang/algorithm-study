#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int n;
int g[51][51] = {0};
int dis[51][51] = {0};
int main(){
    cin>>n;
    while(1){
        int f1, f2;
        cin>>f1>>f2;
        if(f1 == -1 && f2 == -1) break;
        g[f1][f2] = 1;
        g[f2][f1] = 1;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(i==j) dis[i][j] = 0;
            else if(g[i][j] != 0) dis[i][j] = 1;
            else dis[i][j] = INF;
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            for(int k = 1; k<=n; k++){
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }
    vector<int> scores;
    vector<int> presidents;
    scores.push_back(0);
    for(int i = 1; i<=n; i++){
        int score = -1;
        for(int j = 1; j<=n; j++){
            if(dis[i][j] > score) score = dis[i][j];
        }
        scores.push_back(score);
    }
    int pscore = *min_element(scores.begin()+1, scores.end());
    for(int i = 1; i<=n; i++){
        if(scores[i] == pscore) presidents.push_back(i);
    }
    cout<<pscore<<" "<<presidents.size()<<'\n';
    sort(presidents.begin(),presidents.end());
    for(int i = 0; i<presidents.size(); i++){
        cout<<presidents[i]<<" ";
    }
    cout<<'\n';
    return 0;
}