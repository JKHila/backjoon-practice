#include <cstdio>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2;i<n;i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;

}

int main(){
    int N,M,cnt = 0;
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%d",&M);
        if(isPrime(M)){
            //printf("%d\n",M);
            cnt++;
        }
    }
    printf("%d\n",cnt);
}