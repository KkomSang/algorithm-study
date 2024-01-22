#include <iostream>
#include <algorithm>
//#define INF 9999999999999999999
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int t = 1; t<=tc; t++){
        int abi[50][3] = {0};
        int n;
        long long remain = 100000001, save = 100000001;
        cin>>n;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<3; j++){
                cin>>abi[i][j];
            }
        }
        if(n<3){
            cout<<"#"<<t<<" "<<-1<<'\n';
            continue;
        }
        for(int i = 0; i<n; i++){
            //cout<<"i:"<<i<<'\n';
            for(int j = 0; j<n; j++){
                if(j != i){
                    //cout<<"j:"<<j<<'\n';
                    for(int k = 0; k< n; k++){
                        if(k != i && k != j){
                            //cout<<"ijk:"<<i<<" "<<j<<" "<<k<<'\n';
                            save = abi[i][1] + abi[i][2] + abi[j][0] + abi[j][2] + abi[k][0] + abi[k][1];
                            //cout<<"save1:"<<save<<'\n';
                            for(int a = 0; a < n; a++){
                                if(a != i && a != j && a != k){
                                    //cout<<"ijka:"<<i<<" "<<j<<" "<<k<<" "<<a<<'\n';
                                    save += (abi[a][0] + abi[a][1] + abi[a][2] - max(abi[a][0],max(abi[a][1],abi[a][2])));
                                }
                            }
                            //cout<<"save2:"<<save<<'\n';
                            if(remain>save) remain = save;
                        }
                    }
                }
            }
        }
        cout<<"#"<<t<<" "<<remain<<'\n';
    }
    return 0;
}