#include <cstdio>
#include <algorithm>

using namespace std;
int N;
int num[81];
bool promising(int n){
    /* for(int i = 0;i<N;i++){
                printf("%d",num[i]);
            }
            printf("\n"); */
    if(n > 0){
        bool flag = false;
        int m = (n+1) / 2;
        for(int i = 0; i<m; i++){
            flag = false;
            for(int j = 0; j<i+1 ;j++){
                //printf("ll%d %d %d %d\n",n-j,n-(i+j+1),num[n-j],num[n-(i+j+1)]);
                if(num[n-j] != num[n-(i+j+1)]){
                    flag = true;
                    break;
                }
            }
            if(!flag)
                return flag;    
        }
        return flag;
    }
    else
        return true;
}
void goodNumber(int n){
    if(promising(n)){
        if(n == N-1){
            for(int i = 0;i<N;i++){
                printf("%d",num[i]);
            }
            printf("\n");
            exit(0);
        }else{
            for(int i = 1;i<=3;i++){
                num[n+1] = i;
                goodNumber(n+1);
            }
        }
    }
}
int main(){
    scanf("%d",&N);

    for(int i = 1;i<=3 ;i++){
        num[0] = i;
        goodNumber(0);
    }

    
}