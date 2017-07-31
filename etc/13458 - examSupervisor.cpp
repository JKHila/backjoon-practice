#include <cstdio>
using namespace std;
int main(){
    int N,B,C;
    long long A[1000001];
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%lld",&A[i]);
    }
    scanf("%d %d",&B,&C);

    long long res = 0;
    for(int i = 0;i<N;i++){
        A[i] -= B; res++;
        if(A[i] > 0){
           res += (A[i] / C);
           if(A[i] % C > 0){
               res++;
           }
        }
    }
    printf("%lld\n",res);

}