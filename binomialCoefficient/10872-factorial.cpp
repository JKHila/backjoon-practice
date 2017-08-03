#include <cstdio>
using namespace std;

int factorial(int n){
    if(n == 0 || n == 1) return 1;
    
    return factorial(n-1)*n;
}

int main(){
    int N = 0;
    scanf("%d",&N);

    printf("%d\n",factorial(N));
}