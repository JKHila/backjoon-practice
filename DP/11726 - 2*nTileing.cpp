#include <cstdio>
using namespace std;
int main(){
    int dp[1001][2];
    int N;
    int mod=10007;
    scanf("%d",&N);

    dp[1][0] = 1;
    dp[1][1] = 0;
    dp[2][0] = 1;
    dp[2][1] = 1;
    for(int i = 3;i<=N;i++){
        dp[i][0] = (dp[i-1][0] + dp [i-1][1])%mod;
        dp[i][1] = (dp[i-2][0] + dp[i-2][1])%mod;
    }
    printf("%d\n",(dp[N][0] + dp[N][1])%mod);
}