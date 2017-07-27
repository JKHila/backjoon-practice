#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int N = 0;
    int d[301][2];
    int step[301];
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &step[i]);
    }

    d[0][0] = step[0];
    d[0][1] = step[0];
    d[1][1] = step[1];
    for (int i = 1; i < N; i++)
    {
        d[i][0] = d[i-1][1]+step[i];
        if(i >= 2)
            d[i][1] = max(d[i-2][0],d[i-2][1])+step[i];
    }

    printf("%d\n",max(d[N-1][0],d[N-1][1]));
}
