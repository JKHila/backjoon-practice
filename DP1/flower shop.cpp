#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int N,M;
    int a[100][100];
    int dp[100][100]={};
    scanf("%d%d",&N,&M);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            scanf("%d",&a[i][j]);
            //dp[i][j] = -999;
        }
    }
    for(int i = 0;i<M-(N-1);i++){
        dp[0][i] = a[0][i];
    }
    for(int i = 1;i<N;i++){
        int mx=-999;       
        for(int j = i;j<M-(N-i-1);j++){
            for(int k = i-1;k<j;k++){
                mx = max(mx,dp[i-1][k]);     
            }
            dp[i][j] += mx + a[i][j];
        }
    }
    int res=-999;
    for(int i = N-1;i<M;i++){
        res = max(res,dp[N-1][i]);
    }
    printf("%d\n",res);
}