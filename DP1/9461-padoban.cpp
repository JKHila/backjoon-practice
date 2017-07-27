#include <cstdio>
using namespace std;

long long d[101];
long long padoban(long long n)
{
    if (n < 3)
        return 1;
    if (d[n] != -1)
        return d[n];

    d[n] = padoban(n - 2) + padoban(n - 3);

    return d[n];
}

int main()
{
    int T;
    scanf("%d", &T);
    int *res = new int[T];

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &res[i]);
    }
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < 102; j++)
        {
            d[j] = -1;
        }
        printf("%lld\n",padoban(res[i]-1));
    }
}