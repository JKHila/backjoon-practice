#include <cstdio>
using namespace std;
int main(){
    int a[9][9];

    int res = 0,x,y;
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            scanf("%d",&a[i][j]);
            if(res < a[i][j]){
                res = a[i][j];
                x = i+1;
                y = j+1;
            }
        }    
    }
    printf("%d\n%d %d\n",res,x,y);
}