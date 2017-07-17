#include <cstdio>
using namespace std;

int main(){
    int N;
    int tp = 0,res = 0;
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%d",&tp);
        res += tp-1;
    }
    printf("%d\n",res+1);
}