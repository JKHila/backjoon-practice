#include <cstdio>
using namespace std;
int dp[10000005];
int main(){
    int N;
    scanf("%d",&N);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2;i<=N;i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 10;
    }
    printf("%d\n",dp[N]);
}