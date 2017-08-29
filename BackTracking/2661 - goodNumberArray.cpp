#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int a[81];
bool promising(int n){
    bool isOk = true;
    for(int i = 1;i<=n/2;i++){
        bool diff = false;
        for(int j = 0;j<i;j++){
            //printf("%d %d\n",n-j,n-i-j);
            if(a[n-j] != a[n-i-j]){
                diff = true;
                break;
            }
        }
        if(!diff){
            isOk = false;
            break;
        }
    }
    return isOk;
}   
void printGoodNumber(){
    for(int i = 1;i<=N;i++){
        printf("%d",a[i]);
    }
    printf("\n");
}
void goodNumber(int i){
    if(promising(i)){
        if(i == N){
            printGoodNumber();
            exit(0);
        }else{
            for(int j = 1;j<=3;j++){
                a[i+1] = j;
                //printf("%d %d\n",i+1,a[i+1]);
                goodNumber(i+1);
            }
        }
    }
}
int main(){
    scanf("%d",&N);

    goodNumber(0);
}