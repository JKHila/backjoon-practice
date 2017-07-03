#include <cstdio>
using namespace std;

int d[1001][1001];

int binomialCoefficient(int n,int k){

    if(d[n][k] > -1) return d[n][k];

    //if(k > n) return 0;
    if(n < 2 || k == 0) {
        d[n][k] = 1; //0제곱, 1제곱일때 항의 계수는 전부 1,양끝 계수는 항상 1
        return d[n][k];
    }


    d[n][k] = binomialCoefficient(n-1,k-1)+binomialCoefficient(n-1,k);
    return d[n][k];
}

int main(){
    int N,K=0;

    scanf("%d %d",&N,&K);
    for(int i = 0;i<1001;i++){
        for(int j = 0;j<1001;j++){
            d[i][j] = -1;
        }
    }
    int res = binomialCoefficient(N,K)%10007;
    for(int i = 0;i<10;i++){
        for(int j =0;j<10;j++){
            printf("%d  ",d[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",res);
}