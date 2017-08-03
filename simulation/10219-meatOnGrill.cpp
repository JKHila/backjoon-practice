#include <cstdio>
using namespace std;



int main(){
    int N=0,H=0,W = 0;
    char meat[11][11];
    scanf("%d",&N);
    
    for(int k = 0;k < N;k++){
        scanf("%d %d",&H,&W);
        for(int i = 0;i<H;i++){
            scanf("%s",meat[i]);
        }
        for(int i = 0;i<H;i++){
            for(int j = W-1;j>=0;j--){
                //printf("%d %d\n",i,j);
                printf("%c",meat[i][j]);
            }
            printf("\n");
        }
    }
}