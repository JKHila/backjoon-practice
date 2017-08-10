#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using  namespace std;

int getDistance(pair<int,int> n, pair<int,int> m){
    return fabs(n.first - m.first) + fabs(n.second - m.second);
}

int main(){
    int N,W;
    pair<int, int> a[1001];
    int dp[1001][1001]={};
    scanf("%d %d",&N,&W);
    
    int x,y;
    for(int i = 0;i<W;i++){
        scanf("%d %d",&x,&y);
        a[i] = make_pair(x,y);
    }

    dp[0][1] = getDistance(make_pair(N,N),a[0]);
    dp[1][0] = getDistance(make_pair(0,0),a[0]);
    
    for(int i = 0;i<=W;i++){
        for(int j = 0;j<=W;j++){
            if(!(i < 2 && j < 2) && i != j){
                int prev = min(i,j) - 1;
                dp[i][j] = min(dp[prev][j] + getDistance(a[i],a[prev]),dp[i][prev] + getDistance(a[j],a[prev]));
            }
        }
    }

    for(int i = 0;i<=W;i++){
        for(int j = 0;j<=W;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    
}