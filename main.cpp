#include <cstdio>
using namespace std;

void Add(int nuA, int deA, int nuB, int deB, int *nuRes, int *deRes){
    *nuRes = deB * nuA + deA * nuB;
    *deRes = deA * deB;
}
int Sub(int nuA, int deA, int nuB, int deB, int *nuRes, int *deRes){
    int n =  deB * nuA - deA * nuB;
    if(n > 0){
        *nuRes = n;
        *deRes = deA * deB;
    }
    return n;
}
void Gcd(int *nu,int *de){
    for(int i = *de;i >0;i--){
        if(*nu % i == 0 && *de % i == 0){
            *nu /= i;
            *de /= i;
        }
    }
}

int main(){
    int T = 0;
    int nu = 0, de = 0;
    int nextNu=0,nextDe = 0;
    int resNu=0,resDe=1;
    scanf("%d",&T);

    
    for(int k = 0;k<T;k++){
        int i = 2;
        scanf("%d %d",&nu,&de);
        nextNu = nu,nextDe = de;
        resNu = 0,resDe = 1;
        while(true){
            //printf("%d %d\n",i,Sub(nextNu,nextDe,1,i,&nextNu,&nextDe));
            if(Sub(nextNu,nextDe,1,i,&nextNu,&nextDe) >= 0){
                Add(resNu,resDe,1,i,&resNu,&resDe);
                Gcd(&resNu,&resDe);
                //printf("res:%d %d\n",resNu,resDe);
                if(nu == resNu && de == resDe){
                    printf("%d\n",i);
                    break;
                }
            }
            i++;
        }
    }
    return 0;
}