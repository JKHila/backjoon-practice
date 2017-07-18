#include <cstdio>
using namespace std;

int dp[1001][1001];
int c[1001][1001];


int candy(int x,int y){
    if(dp[x][y] != -1){
        return dp[x][y];
    }

    dp[x][y] += candy(x-1,y) + candy(x,y-1) + candy(x-1,y-1);
    return c[x][y];
}

int main(){
    int N,M;
    scanf("%d %d",&N,&M);

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            dp[i][j] = -1;
            scanf("%d",&c[i][j]);
        }    
    }
    
    printf("%d\n",dp[N][M]);

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            printf("%d ",dp[i][j]);
        }
    printf("\n");
    }
}