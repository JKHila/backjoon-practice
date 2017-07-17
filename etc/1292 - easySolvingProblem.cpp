#include <cstdio>
using namespace std;

int main(){
    int N,M;
    int a[1001];

    scanf("%d%d",&N,&M);
    int T = 0;
    for(int i = 0;i<1000;i++){
        for(int j = 0;j<i+1;j++){
            if(T<1000){
                a[T++] = i+1;
            }
        }
    }
    int res = 0;
    for(int i = N-1;i != M;i++){
        res += a[i];
    }
    printf("%d\n",res);
}