#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int remote[10];

int possible(int n){
    if(n == 0){
        if(remote[0] != -1)return 1;
        else return -1;
    }
    int len = log10(n)+1;
    int cur = 0;
    for(int i = 0;i<len;i++){
        cur = n % (int)pow(10,len-i) / (int)pow(10,len-(i+1));
        if(remote[cur] == -1){
            return -1;
        }
    }
    return len;
}

int main(){
    int N = 0;
    int M = 0;
    scanf("%d",&N);
    scanf("%d",&M);

    
    int tp = 0;
    for(int i = 0;i<M;i++){
        scanf("%d",&tp);
        remote[tp] = -1;
    }

    for(int i = 0;i<10;i++){
        printf("%d\n",remote[i]);
    }
    int cur = fabs(100 - N);
    //printf("ss%d %f\n",(int)pow(10,2),log10(1)+1);
    int res=0, minVal = 1000000, press = 0;
    for(int i = 0;i<1000000;i++){
        press = possible(i);
        if(press > 0){
            res = fabs(N - i) + press;
            if(res == 1) printf("dd%d\n",i);
            if(res < minVal){
                minVal = res;
            }
            /*if(res == 0)
                printf("d:%d\n",i);*/
        } 
    }
    int ret = min(minVal,cur);
    printf("%d\n",ret);
}