#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int N = 0;
    int d[501][501];
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }
     for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (i > 0)
            {
                if(j == 0){
                    d[i][j] += d[i-1][j];
                }else if(j == i){
                    d[i][j] += d[i-1][j-1];
                }else{
                    d[i][j] += max(d[i-1][j],d[i-1][j-1]);
                }
            }
        }
    }
    
    int max = d[N-1][0];
    for(int i = 1;i<N;i++){
        if(d[N-1][i] > max){
            max = d[N-1][i];
        }
    }
    printf("%d\n",max);
}