#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int N,res;
    int a[1001];
    int d[1001] = {};
    scanf("%d",&N);

    for(int i = 1;i<=N;i++){
        scanf("%d",&a[i]);
        d[i] = a[i];
    }
    res = d[1];
    for(int i = 1;i<=N;i++){
        for(int j = i-1;j > 0;j--){
            if(a[i] > a[j]){
                d[i] = max(d[i],d[j] + a[i]);
                if(res < d[i]) res = d[i];
                //printf("%d %d\n",i,d[i]);
            }
        }
    }
    printf("%d\n",res);
}