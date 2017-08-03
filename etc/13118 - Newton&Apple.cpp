#include <cstdio>
using namespace std;

int main(){
    int p[5];

    for(int i = 1;i<5;i++){
        scanf("%d",&p[i]);
    }
    int x,y,r;
    scanf("%d %d %d",&x,&y,&r);

    int res = 0;
    for(int i = 1;i<5;i++){
        if(p[i] == x){
            res = i;
            break;
        }
    }
    printf("%d\n",res);
}