#include <cstdio>
using namespace std;

int main(){
    int N,K;
    int coin[10];
    int res = 0;
    scanf("%d %d",&N,&K);

    for(int i = 0;i<N;i++){
        scanf("%d",&coin[i]);
    }

    while(K > 0){
        for(int i = N-1;i >= 0;i--){
            if(coin[i] <= K){
                K -= coin[i];
                res++;
                break;
            }
        }
    }
    printf("%d\n",res);
}