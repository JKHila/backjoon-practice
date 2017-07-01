#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N = 0;
    int d[10001][2];
    int a[10001];
    scanf("%d",&N);

    for(int i = 0;i<N;i++){
        scanf("%d",&a[i]);
    }

    d[0][0] = 0;
    d[0][1] = a[1];
    for(int i = 0;i<N;i++){
        d[i][0] = d[i-1][1]+a[i];
        d[i][1] = max(d[i-2][0],d[i-2][1])+a[i];
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<2;j++){
            printf("%d  ",d[i][j]);
        }
        printf("\n");
    }

    int i = max(d[N-2][1],d[N-2][0]);
    int j = max(d[N-1][1],d[N-1][0]);
    printf("%d\n",max(i,j));

}