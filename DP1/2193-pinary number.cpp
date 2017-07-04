#include <cstdio>
#include <queue>
using namespace std;

long long d[91][2];

int main(){
    int N = 0;
    
    scanf("%d",&N);

    d[1][0] = 0;
    d[1][1] = 1;
    
    for(int i = 2;i<=N;i++){
        d[i][0] = d[i-1][1] + d[i-1][0];
        d[i][1] = d[i-1][0];
    }

    printf("%lld\n",d[N][0]+d[N][1]);
}