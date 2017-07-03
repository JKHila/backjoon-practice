#include <cstdio>
using namespace std;


long long int combination(long long int n,long long int m){
    if(n == m){
        return 1;
    }else
        return (n * combination(n-1,m)) / (n-m);
}

int main(){
    long long int N,M = 0;
    long long int K[10000][2];
    int num = 0;

    for(int i = 0;i<10000;i++){
        scanf("%lld %lld",&K[i][0],&K[i][1]);
        if(K[i][0] == 0 && K[i][1] == 0) break;
        num++;
    }

    for(int i = 0;i<num;i++){
        printf("%lld\n",combination(K[i][0],K[i][1]));
    }
    
}