#include <cstdio>
using namespace std;
int func(){
    int N,M;
    int A[1001],B[1001];
    int count[1001]={};
    scanf("%d %d", &N, &M);
    for (int j = 0; j < N; j++)
    {
        scanf("%d", &A[j]);
    }
    for (int k = 0; k < M; k++)
    {
        scanf("%d", &B[k]);
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (B[i] >= A[j])
            {
                count[j]++;
                break;
            }
        }
    }
    int mx = count[0];
    int res = 0;
    for(int i = 1;i<N;i++){
        //printf("%d ",count[i]);
        if(mx < count[i]){
            res = i;
            mx = count[i];
        }
    }
    return res;
}
int main(){
    int T;
    
    scanf("%d",&T);
    for(int i = 0; i < T ; i++){
       int res = func();
       printf("#%d %d\n",i+1,res+1);
    }
}