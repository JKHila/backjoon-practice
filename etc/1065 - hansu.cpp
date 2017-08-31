#include <cstdio>
using namespace std;
bool hansu(int n){
    if (n < 100) return true;
    int m = n;
    int a = n % 10;
    n /= 10;
    int b = n % 10;
    while(true){
        n /= 10;
        if(n == 0) break;
        if(b - n % 10 != a - b)
            return false;
    }
    return true;
}
int  main(){
    int N;
    scanf("%d",&N);

    int res = 0;
    for(int i = 1;i<=N;i++){
        if(hansu(i)) res++;
    }
    printf("%d\n",res);
}