#include <cstdio>
using namespace std;



int main(){
    int N = 0;
    int mod = 1000000000;
    int d[101][11];
    scanf("%d",&N);
    
    for(int i = 1;i<10;i++){
        d[1][i] = 1;
    }

    for(int i = 2;i<=N;i++){
        for(int j = 0;j<10;j++){
            if(j == 0){
                d[i][j] = d[i-1][1];
                d[i][j] %= mod;
            }else if(j == 9){
                d[i][j] = d[i-1][8];
                d[i][j] %= mod;
            }else{
                d[i][j] = d[i-1][j-1] + d[i-1][j+1];
                d[i][j] %= mod;
            }
        }
    }

    int res = 0;
    for(int j = 0;j<10;j++){
        res += d[N][j];
        res %= mod;
    }
    printf("%d\n",res);
}