#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N = 0;
    int dp[1000000]={0,0,1,1,};
    scanf("%d",&N);

    for(int i = 4;i<=N;i++){
       if(i%3==0){
           dp[i] = min(dp[i/3],dp[i-1])+1;
       }else if(i%2 == 0){
           dp[i] = min(dp[i/2],dp[i-1])+1;
       }else{
           dp[i] = dp[i-1]+1;
       }
    }
    printf("%d\n",dp[N]);
}