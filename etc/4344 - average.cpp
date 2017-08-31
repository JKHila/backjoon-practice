#include <cstdio>
#include <cmath>
using namespace std;

double Rounding( double x, int digit )
{
    return ( floor( (x) * pow( float(10), digit ) + 0.5f ) / pow( float(10), digit ) );
}
int main(){

    int T;
    scanf("%d",&T);
    while(T > 0){
        int N, sum = 0;
        int a[1001];
        scanf("%d",&N);
        for(int i = 0;i<N;i++){
            scanf("%d",a+i);
            sum += a[i];
        }
        float ave = sum / N;
        int st = 0;
        for(int i = 0;i<N;i++){
            if(a[i] > ave){
                st++;
            }
        }
        
        float res = (float)st / float(N) * 100;
        printf("%.3f%%\n",Rounding(res,3));
        T--;
    }
} 