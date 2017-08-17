#include <cstdio>
using namespace std;

int func(int n,int m){
    int dp[31][31]={};
    for(int i = 0;i<=m;i++) dp[1][i] = i;
    for(int i = 2;i<=n;i++){
        for(int j = i;j<=m;j++){
             for(int k = j;k>=i;k--){
                 dp[i][j] += dp[i-1][k-1];
             }
        }
    }
    return dp[n][m];
}
int main(){
    int T;
    scanf("%d",&T);

    int N,M;
    while(T>0){
        scanf("%d%d",&N,&M);
        printf("%d\n",func(N,M));
        T--;
    }
    
}