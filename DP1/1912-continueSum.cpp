#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N = 0;
    int a[100001];
    int d[100001];
    scanf("%d",&N);

    int res = -10001;
    for(int i = 0;i<N;i++){
        scanf("%d",&a[i]);
        d[i] = max(a[i],d[i-1]+a[i]);
        if(d[i] > res){
            res = d[i];
        }
    }
    printf("%d\n",res);
}