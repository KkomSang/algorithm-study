#include <iostream>
#include <numeric>
using namespace std;

/* 부분집합 평균들의 평균 == 집합의 평균 */
// int main(){
//     int tc;
//     cin>>tc;
//     for(int t = 1; t<=tc; t++){
//         int set[8] = {0};
//         int n;
//         double sum = 0;
//         cin>>n;
//         for(int i = 0; i<n; i++){
//             cin>>set[i];
//         }
//         sum = accumulate(set,set+n,0.0);
//         int i = sum/n;
//         double dec = sum/n;
//         cout<<"#"<<t<<" ";
//         if(dec-i == 0){
//             cout<<i<<'\n';
//         }
//         else{
//             printf("%.20lf\n",sum/n);
//         }
//     }
//     return 0;
// }

/* 비트마스크를 이용한 부분집합*/
int main(){
    int tc, n;
    cin>>tc;
    for(int t = 1; t<=tc; t++){
        int set[8];
        cin>>n;
        double final_sum = 0;
        for(int i = 0; i<n ;i++){
            cin>>set[i];
        }
        for(int i = 0; i< (1 << n); i++){
            int s = 0;
            double sum = 0;
            int cou = 0;
            for(int j = 0; j< n; j++){
                if(i&(1<<j)){
                    sum += set[j];
                    cou += 1;
                }
            }
            if(cou == 0) continue;
            final_sum += sum/cou;
        }
        cout<<"#"<<t<<" ";
        printf("%.14lf\n",final_sum/((1<<n)-1));
    }
    return 0;
}