#include <cstdio>
using namespace std;

int main(){
    int N,kim,lim = 0;
    int round = 1;
    scanf("%d %d %d",&N,&kim,&lim);

    while(true){
        if(kim%2 == 0 && lim == kim-1)
            break;
        else if(kim%2 == 1 && lim == kim+1)
            break;

        if(kim%2 == 0) kim /= 2;
        else{ kim += 1; kim /= 2;}

        if(lim%2 == 0) lim /= 2;
        else{ lim += 1; lim /= 2;}
        
        round++;
    }
    printf("%d\n",round);
}