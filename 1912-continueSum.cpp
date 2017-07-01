#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N = 0;
    int a[100001];
    int d[100001];
    scanf("%d",&N);

    for(int i = 0;i<N;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<N;i++){
        d[i] = max(a[i],d[i-1]+a[i]);
    }

    int res = d[0];
    for(int i = 0;i<N;i++){
        if(d[i] > res){
            res = d[i];
        }
    }
    printf("%d\n",res);
}