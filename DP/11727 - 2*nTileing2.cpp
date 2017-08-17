#include <cstdio>
using namespace std;

int main(){
    int N;
    int dp[1001]={};
    int mod = 10007;
    scanf("%d",&N);

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2;i<=N;i++){
        dp[i] = dp[i-1] + dp[i-2]*2;
        dp[i] %= mod;
    }
    printf("%d\n",dp[N]%mod);
}