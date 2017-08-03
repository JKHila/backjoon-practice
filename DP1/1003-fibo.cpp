#include <iostream>
#include <cstdio>
using namespace std;

int cnt[2];

int fibonacci(int n) {
    if (n==0) {
        cnt[0]++;
        return 0;
    } else if (n==1) {
        cnt[1]++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(void){
    int d = 0;
    int N = 0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&d);
        cnt[0] = 0;
        cnt[1] = 0;
        fibonacci(d);
        printf("%d %d\n",cnt[0],cnt[1]);
    }
    return 0;
}