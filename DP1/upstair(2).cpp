#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int N;
    int a[301];
    int dp[301]={};
    scanf("%d",&N);
    for(int i = 1;i<=N;i++){
        scanf("%d",a+i);
    }
    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = max(dp[0],dp[1])+a[2];
    for(int i = 3;i<=N;i++){
        dp[i] = max(dp[i-2],dp[i-3]+a[i-1]) + a[i];
    }
    
    printf("%d\n",dp[N]);
}