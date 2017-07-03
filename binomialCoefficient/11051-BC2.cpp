#include <cstdio>
using namespace std;

int main(){
    int N,K=0;
    int d[1001][1001];
    scanf("%d %d",&N,&K);
    d[0][0] = 1; 
    d[1][0] = 1; 
    d[1][1] = 1;
    for(int i = 2;i<=N;i++){
        for(int j =0;j<=i;j++){
            d[i][j] = d[i-1][j-1]+d[i-1][j];
        }
    }
    printf("%d\n",d[N][K]);
}