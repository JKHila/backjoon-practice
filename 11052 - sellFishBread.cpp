#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int N;
    int dp[1001]={};
    int a[1001];
    scanf("%d",&N);
    for(int i = 1;i<=N;i++){
        scanf("%d",a+i);
        dp[i] = a[i];
    }
    for(int i = 2;i<=N;i++){
        for(int j = 1;j<=i;j++){
            dp[i] = max(dp[i],dp[i-j]+a[j]);
            //printf("%d %d\n",j,dp[i]);
        }
        //printf("\n");
    }
    printf("%d\n",dp[N]);
}