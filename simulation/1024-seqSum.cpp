#include <cstdio>
using namespace std;

int seqSum(int n)
{ //1부터 n 까지의 합
    return n * (n + 1) / 2;
}

void showSeq(int n, int l)
{
    for (int i = n; i < l + n; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    int N, L = 0, x = -1;
    scanf("%d %d", &N, &L);

    for (int i = L; i <= 100; i++)
    {
        
        if ((N - seqSum(L - 1)) / L >= 0 && (N - seqSum(L - 1)) % L == 0)
        {
            x = (N - seqSum(L - 1)) / L;
            showSeq(x, L);
            return 0;
        }
        L++;
    }
    printf("-1\n");
    return 0;
   
}