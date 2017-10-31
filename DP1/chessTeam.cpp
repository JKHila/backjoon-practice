#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int arr[1001][2] = {};
    int dp[1001][16][16] = {0};
    int n=1;
    while(scanf("%d %d", &arr[n][0], &arr[n][1]) != EOF){
        n++;
    };
    for (int i = 1;i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int k = 0; k <= i; k++)
            {
                dp[i][j][k] = dp[i-1][j][k];
                if (j > 0)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + arr[i][0]);
                if (k > 0)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + arr[i][1]);

                //printf("%d %d %d %d %d %d\n",i,j,k,dp[i-1][j][k],dp[i-1][j-1][k] + arr[i][0],dp[i-1][j][k-1]+arr[i][1]);
            }
        }
    }
    /*for(i = 1;i<=31;i++){
        for(int j = 0;j<=i;j++){
            for(int k = 0;k<=i;k++){
                printf("%d ",dp[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
        
    }*/
    printf("%d\n", dp[n - 1][15][15]);
}