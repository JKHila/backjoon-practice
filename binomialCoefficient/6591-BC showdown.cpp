#include <cstdio>
using namespace std;


int main(){
    int n,k = 0;
    long long int res;
    while(true){
        res = 1;
        scanf("%d %d",&n,&k);

        if(n==0 && k==0) break;
        if(k > n-k) k = n-k;

        for(int i = 1;i<=k;i++){
            res *= n--;
            res /= i;
        }
        printf("%lld\n",res);
    }
    
}