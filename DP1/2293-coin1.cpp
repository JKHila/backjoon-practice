#include <cstdio>
using namespace std;

int main(){
    int N[2];
    int val[101];
    int d[10001] ={};

    scanf("%d %d",&N[0],&N[1]);

    for(int i = 0;i<N[0];i++){
        scanf("%d",&val[i]);
    }
    d[0] = 1;
    for(int i = 0;i<N[0];i++){
        for(int j = 0;j<=N[1];j++){
            if(j>=val[i])
                d[j] += d[j-val[i]];
        }
    }

    printf("%d\n",d[N[1]]);
}