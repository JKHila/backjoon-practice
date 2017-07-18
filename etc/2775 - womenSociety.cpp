#include <cstdio>
using namespace std;

int main(){
    long long dp[15][15] ={};
    int T,k,n;
    scanf("%d",&T);

    for(int i = 1;i<=14;i++){
        dp[0][i] = i;
    }
    for(int i = 1;i<=14;i++){
        for(int j = 1;j<=14;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    for(int i = 0;i<T;i++){
        scanf("%d %d",&k,&n);
        printf("%lld\n",dp[k][n]);
    }
    /*for(int i = 0;i<=14;i++){
        for(int j = 0;j<=14;j++){
            printf("%d:%lld ",i,dp[i][j]);
        }
        printf("\n");
    }*/
}