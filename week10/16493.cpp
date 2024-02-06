#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int n, m;//주어진 일 수, 챕터 수
    vector<pair<int, int> > chapter; // <일 수, 페이지 수>
    //int chapter[21][2] = {0};
    int dp[21][201] = {0}; //[i][j]: i챕터를 포함하고 j일이 걸렸을 때의 읽은 페이지 수 저장
    cin>>n>>m;
    chapter.push_back(make_pair(0,0));
    for(int i = 0; i<m; i++){
        int day, page;
        cin>>day>>page;
        chapter.push_back(make_pair(day, page));
    }
    for(int i = 1; i<=m; i++){
        for(int j = 0; j<=n; j++){
            if(j-chapter[i].first >= 0) dp[i][j] = max(dp[i-1][j-chapter[i].first] + chapter[i].second, dp[i-1][j]);
            dp[i][j] = max(dp[i-1][j],dp[i][j]);
        }
    }
    cout<<dp[m][n]<<'\n';
    return 0;
}