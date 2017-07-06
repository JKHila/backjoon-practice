#include <cstdio>
using namespace std;

int Gcd(int a,int b){
    return b == 0 ? a : Gcd(b,a%b);
}

int main(){
    int T = 0;
    int a = 0, b = 0, x = 0, g = 0;
    scanf("%d",&T);

    for(int k = 0;k<T;k++){
        scanf("%d %d",&a,&b);

        while(a != 1){

            x = b / a +1;

            a = a * x - b;
            b = b * x;
            
            
            g = Gcd(a,b);
            a /= g;
            b /= g;

        }
        printf("%d\n",b);
        
    }
    return 0;
}