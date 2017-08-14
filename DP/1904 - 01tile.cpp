#include <cstdio>
using namespace std;
int main(){
    int N;
    int mod = 15746;
    int dp[1000001][2];
    scanf("%d",&N);
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    for(int i = 3;i<=N;i++){
        dp[i][0] = (dp[i-2][0] + dp[i-2][1]) % mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % mod;
    }
    /*for(int i = 1;i<=N;i++){
        for(int j = 0;j<2;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n",(dp[N][0]+ dp[N][1])%mod);
}