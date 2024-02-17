#include <iostream>
#include <vector>
using namespace std;
int n, m, chi = 0, hou = 0, result = 987654321;
vector<pair<int,int> > chicken; //<행, 열>
vector<pair<int,int> > house;//<행, 열>
int com[14] = {0};
int dis(){
    int res = 0;
    for(int i = 0; i< hou; i++){
        int d = 987654321;
        for(int j = 0; j<m; j++){
            if(d>(abs(house[i].first - chicken[com[j]].first)+abs(house[i].second - chicken[com[j]].second))){
                d = (abs(house[i].first - chicken[com[j]].first)+abs(house[i].second - chicken[com[j]].second));
            }
        }
        res += d;
    }
    return res;
}

void combination(int depth, int next){
    if(depth == m){
        if(result>dis()) result = dis();
        return;
    }
    for(int i = next; i<chi; i++){
        com[depth] = i;
        combination(depth + 1, i + 1);
    }
}

int main(){
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            int which;
            cin>>which;
            if(which == 2){
                chicken.push_back(make_pair(i,j));
                chi++;
            }
            else if(which == 1){
                house.push_back(make_pair(i,j));
                hou++;
            } 
        }
    }
    combination(0,0);
    cout<<result<<'\n';
    return 0;
}