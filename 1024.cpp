#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    long long N, L = 0;
    queue<long long> res;
    scanf("%lld %lld", &N, &L);

    int i = 0;
    while (true)
    {
        i = N / L;
        if(i < 1){
            printf("-1\n");
            return 0;
        }
        //printf("i:%d L:%d\n",i,L);
        if (L % 2 == 0 && i >= L / 2 - 1 && L / 2 * (2 * i + 1) == N)
        {
            for (long long j = (-1 * L / 2) + 1; j <= L / 2; j++)
            {
                res.push(i + j);
            }
            break;
        }
        else if (L % 2 == 1 && i >= L / 2 && i * L == N)
        {
            for (long long j = L / 2 * -1; j <= L / 2; j++)
            {
                res.push(i + j);
            }
            break;
        }
        L++;
        if(L > 100){
            printf("-1\n");
            return 0;
        }
    }

    if(res.size() > 100){
        printf("-1\n");
        return 0;
    }
    while(!res.empty()){
        printf("%lld ",res.front());
        res.pop();
    }
    printf("\n");

}