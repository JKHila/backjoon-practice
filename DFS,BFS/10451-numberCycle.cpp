#include <cstdio>
using namespace std;

int main(){
    int T,N;
    int arr[1000];
    int check[1000] = {};
    int j = 0,res = 0;
    scanf("%d",&T);

    while(T > 0){
        res = 0;
        j = 0;
        scanf("%d",&N);
        for(int i = 1;i<=N;i++){
            scanf("%d",&arr[i]);
            check[i] = 0;
        }
        for(int i = 1;i<=N;i++){
            if(check[i] != 1){
                j = arr[i];
                while(j != i){
                    check[j] = 1;
                    j = arr[j];
                }
                res++;
            }
        }
        printf("%d\n",res);
        T--;
    }
}