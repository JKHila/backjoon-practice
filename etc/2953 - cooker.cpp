#include <cstdio>

int main(){
    int T = 0;

    int tp = 0;
    int res = 0,max = 0,resNum = 0;

    while(T < 5){
        res = 0;
        for(int i = 0;i<4;i++){
            scanf("%d",&tp);      
            res += tp;  
        }
        if(max < res){
            max = res;
            resNum = T+1;
        }
        T++;
    }

    printf("%d %d\n",resNum,max);
}