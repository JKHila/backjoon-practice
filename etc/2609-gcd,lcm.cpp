#include <cstdio>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b,a%b);
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main(){
    int N,M;
    scanf("%d %d",&N,&M);

    printf("%d\n%d\n",gcd(N,M),lcm(N,M));
}