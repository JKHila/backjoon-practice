#include <cstdio>
using namespace std;

int binomialCoefficient(int n,int k){
    if(k > n) return 0;
    if(n == 0 || n == 1) return 1;
    if(k == 0) return 1;

    return binomialCoefficient(n-1,k-1)+binomialCoefficient(n-1,k);
}

int main(){
    int N ,K= 0;
    scanf("%d %d",&N,&K);

    printf("%d\n",binomialCoefficient(N,K));
}