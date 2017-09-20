#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double x,y,c;
double getWidth(double w){
    return (c / sqrt(x*x - w*w)) + (c / sqrt(y*y - w*w)) - 1;
}
double binarySearch(double low, double high){
    double mid = (low + high) / 2;
    double equ = getWidth(mid);
    if(low > high){
        return 0;
    }
    if(equ <= 0.0000001 && equ >= 0){
        return mid;
    }else if(equ < 0){
        return binarySearch(mid,high);
    }else{
        return binarySearch(low,mid);        
    }
}
int main(){
    scanf("%lf%lf%lf",&x,&y,&c);
    double ans = binarySearch(0,min(x,y));
    printf("%.3f\n",ans);
}