#include <cstdio>
using namespace std;

int dp[46];
int fibo(int n){
    if(dp[n] > 0){
        return dp[n];
    }
    if(n == 0){
        dp[n] = 0;
    }else if (n < 3){
        dp[n] = 1;
        return 1;
    }else{
        dp[n] = fibo(n-2) + fibo(n-1);
    }
    return dp[n];
}

int main(){
    int N = 0;
    scanf("%d",&N);

    printf("%d\n",fibo(N));
}