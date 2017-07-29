#include <cstdio>
using namespace std;

int main(){
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);

    int res = 0;
    if(a <= 0){
        res += c * a * -1;
        res += d;
        res += b*e;    
    }else{
        res += (b-a) * e;
    }
    printf("%d\n",res);
    
}
