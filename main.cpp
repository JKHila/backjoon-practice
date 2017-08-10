#include <cstdio>
using namespace std;
int dp[10000005];
int func(int n){
    if(n == 1 || n == 0) return 1;
    if(dp[n]){
        return dp[n];
    }

    dp[n] = func(n-1) % 10+func(n-2) % 10;
    dp[n] %= 10;
    return dp[n] % 10;
}
int fibo(int n){
    if(n == 1 || n == 0) return 1;
    return fibo(n-1) + fibo(n-2);
}
int main(){
    int N;
    scanf("%d",&N);
    printf("%d\n",fibo(N)%10);
}