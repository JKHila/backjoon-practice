#include <cstdio>
using namespace std;

int mod = 10007;

long upNumber(int N){
    int d[1001][11] ={};

    for(int i = 0;i<10;i++){
        d[1][i] = 1;
    }
    for(int i = 2;i<=N;i++){
        for(int j = 0;j<10;j++){
            for(int k = 0;k<10;k++){
                if(k >= j)
                    d[i][j] += d[i-1][k];
                    d[i][j] %= mod;
            }
        }
    }
    long res = 0;
    for(int i = 0;i<10;i++){
        res += d[N][i];
        res %= mod;
    }
    return res;
}

int main(){
    int N;
    scanf("%d",&N);
    printf("%ld\n",upNumber(N));            
    
    /*for(int i = 1;i<=100;i++){
        printf("%ld\n",upNumber(i));            
    }*/
}