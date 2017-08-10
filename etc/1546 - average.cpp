#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
double round( double value, int pos )
{
     double temp;
     temp = value * pow( 10, pos );  // 원하는 소수점 자리수만큼 10의 누승을 함
     temp = floor( temp + 0.5 );          // 0.5를 더한후 버림하면 반올림이 됨
     temp *= pow( 10, -pos );           // 다시 원래 소수점 자리수로
 
     return temp;
}

int main(){
    int N,mx=0;
    int a[1001];
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%d",&a[i]);
        mx = max(mx,a[i]);
    }
    double res = 0;
    for(int i = 0;i<N;i++){
        double tp = a[i] / (double)mx * 100.0;
        tp = round(tp,3);
        res += tp;
    }
    printf("%.2f\n",res/N);
}