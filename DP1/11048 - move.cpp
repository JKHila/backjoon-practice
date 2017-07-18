#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
    int N,M;
    int dp[1001][1001] = {};
    int c[1001][1001];
    scanf("%d %d",&N,&M);

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            scanf("%d",&c[i][j]);
            dp[i][j] = c[i][j] + max(dp[i-1][j],max( dp[i][j-1] , dp[i-1][j-1]));
        }    
    }
    
    printf("%d\n",dp[N][M]);

    /*for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            printf("%d ",dp[i][j]);
        }
    printf("\n");
    }*/
}