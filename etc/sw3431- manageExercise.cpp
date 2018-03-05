#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int T,L,U,X,res;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        scanf("%d %d %d",&L,&U,&X);
        if(X < L){
            res = L - X;
        }else if( X > U)
            res = -1;
        else 
            res = 0;
        printf("#%d %d\n",i+1,res);
    }
}