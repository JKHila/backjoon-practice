#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    char chess[8][8];
    int res = 0;
    for(int i = 0;i<8;i++){
        scanf("%s",chess[i]);
    }

    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(i%2 == 0 && j%2==0 && chess[i][j] =='F') res++;
            else if(i%2 == 1 && j%2 ==1 && chess[i][j] == 'F') res++;
        }
    }
    printf("%d\n",res);
}