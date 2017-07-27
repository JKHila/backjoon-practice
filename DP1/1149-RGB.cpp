#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int table[1000][3] = {};

int main()
{
    int N = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &r, &g, &b);

        if (i == 0)
        {
            table[0][0] = r;
            table[0][1] = g;
            table[0][2] = b;
        }
        else
        {
            table[i][0] = min(table[i-1][1],table[i-1][2]) + r;
            table[i][1] = min(table[i-1][0],table[i-1][2]) + g;
            table[i][2] = min(table[i-1][0],table[i-1][1]) + b;
        }
    }
    printf("%d\n",min(min(table[N-1][0],table[N-1][1]),table[N-1][2]));
}