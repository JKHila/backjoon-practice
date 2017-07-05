#include <cstdio>
using namespace std;

int main()
{
    int N, T = 0;
    int d[12];
    scanf("%d", &T);

    for (int k = 0; k < T; k++)
    {
        scanf("%d", &N);

        for (int i = 0; i < 12; i++)
        {
            d[i] = 0;
        }
        d[0] = 1;
        for (int j = 1; j <= N; j++)
        {
            for (int i = 1; i <= 3; i++)
            {

                if (j >= i)
                {
                    d[j] += d[j - i];
                }
            }
        }
        printf("%d\n", d[N]);
    }
}