#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int A,B,C =0;
    int total = 0;
    int num[11] ={};
    scanf("%d %d %d",&A,&B,&C);
    
    total = A*B*C;

    int tp = 0;
    for(int i = 1;i<=log10(total)+1;i++){
        tp = (total % int(pow(10,i))) / (int)pow(10,i-1);
        num[tp]++;
        
    }

    for(int i = 0;i<10;i++){
        printf("%d\n",num[i]);
    }

}