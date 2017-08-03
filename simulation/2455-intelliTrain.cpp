#include <cstdio>
using namespace std;

int main(){
    int cur = 0;
    int in,out = 0;

    int res = 0;
    for(int i =0;i<4;i++){
        scanf("%d %d",&out,&in);
        cur -= out;
        cur += in;
        if(res < cur) res = cur;
    }

    printf("%d\n",res);

}