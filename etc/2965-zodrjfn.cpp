#include <cstdio>
using namespace std;

int main(){
    int N[3] = {0};
    int cnt=0;
    scanf("%d %d %d",&N[0],&N[1],&N[2]);
    while(true){
        int aSide = N[1]-N[0];
        int bSide = N[2]-N[1];
        if(aSide == 1 && bSide == 1){
            break;
        }else if(aSide > bSide){
            N[2] = N[1];
            N[1] = N[1]-1;
        }else if(aSide <= bSide){
            N[0] = N[1];
            N[1] = N[1]+1;
        }
        cnt++;
    }
    printf("%d\n",cnt);
}