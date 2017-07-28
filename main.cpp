#include <cstdio>
using namespace std;

unsigned long long pow(int n){
    unsigned long long res = 1;
    for(int i = 0;i<n;i++){
        res *= 2;
    }
    return res;
}

int main(){
    int N;
    scanf("%d",&N);
    printf("%llu\n",pow(N));
}