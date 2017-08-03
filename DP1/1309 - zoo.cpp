#include <cstdio>
using namespace std;
int main(){
    int N;
    int dp[100001];
    int mod = 9901;
    scanf("%d",&N);
    
    dp[0] = 1;
    dp[1] = 3;

    for(int i = 2;i<=N;i++){
        dp[i] = (dp[i-2] + dp[i-1]*2);
        dp[i] %= mod;
    }

    printf("%d\n",dp[N]%mod);
}