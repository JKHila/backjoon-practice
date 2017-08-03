#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int N = 0;
    int d[10001];
    int a[10001];
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
    }

    d[0] = 0;
    d[1] = a[1];
    d[2] = a[1] + a[2];
    for (int i = 3; i <= N; i++)
    {
        d[i] = max(d[i-1],max(d[i-2]+a[i],d[i-3]+a[i-1]+a[i]));
    }
    int res = 0;
    for(int i = 1;i<=N;i++){
        if(d[i] > res){
            res = d[i];
        }
    }
    printf("%d\n", res);
}