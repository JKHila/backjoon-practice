#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int T,N;
    int map[2][100000];
    int dp[2][100000];
    scanf("%d",&T);

    while(T > 0){
        scanf("%d",&N);
        for(int i = 0;i<2;i++){
            for(int j = 0;j<N;j++){
                scanf("%d",&map[i][j]);
                dp[i][j] = map[i][j];
            }
        }
        dp[0][0] = map[0][0];
        dp[1][0] = map[1][0];
        dp[0][1] += dp[1][0];
        dp[1][1] += dp[0][0];
        int res = max(dp[1][0],dp[0][0]);
        
        for(int j = 2;j<N;j++){
            dp[0][j] += max(dp[0][j-2],max(dp[1][j-2],dp[1][j-1]));
            dp[1][j] += max(dp[0][j-2],max(dp[1][j-2],dp[0][j-1]));
            res = max(dp[1][j],dp[0][j]);
        }
        /*for(int i = 0;i<2;i++){
            for(int j = 0;j<N;j++){
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }*/
        printf("%d\n",res);
        T--;
    }
}