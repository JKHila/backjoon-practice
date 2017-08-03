#include <cstdio>
using namespace std;

int map[101][101];
int dx[2] = {1,0};
int dy[2] = {0,1};
int N;
long long dp[101][101];

long long Jump(int x, int y){
    if(x == N-1 && y == N-1){
        return 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    if(dp[x][y] == -1){
        dp[x][y] = 0;
    }
    int nx,ny;
    for(int i = 0;i<2;i++){
        nx = x + (dx[i] * map[x][y]);
        ny = y + (dy[i] * map[x][y]);
        
        dp[x][y] += Jump(nx,ny);
    }
    return dp[x][y];
}

int main(){
    scanf("%d",&N);

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            dp[i][j] = -1;
            scanf("%d",&map[i][j]);
        }
    }
    Jump(0,0);
    /*for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            printf("%lld ",dp[i][j]);
        }
        printf("\n");
    }*/
    printf("%lld\n",dp[0][0]);

}