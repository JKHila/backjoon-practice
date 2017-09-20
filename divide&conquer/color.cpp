#include <cstdio>
using namespace std;
int map[128][128];
int white,pink = 0;
bool check(int x1,int y1,int x2,int y2){
    int first = map[x1][y1];
    bool ret = true;
    for(int i = x1;i<=x2;i++){
        for(int j = y1;j<=y2;j++){
            if(map[i][j] != first){
                ret = false;
            }
        }
    }
    return ret;
}
void color(int x1,int y1,int x2,int y2){
    if(!check(x1,y1,x2,y2)){
        //1 2
        //3 4
        int beginX = (x1 + x2 + 1) / 2;
        int endX = (x1 + x2 - 1) / 2;
        int beginY = (y1 + y2 + 1) / 2;
        int endY = (y1 + y2 - 1) / 2;
        color(x1,y1,endX,endY); //1
        color(x1,beginY,endX,y2); //2
        color(beginX,y1,x2,endY); //3
        color(beginX,beginY,x2,y2); //4      
    }else{
        if(map[x1][y1] == 0)    white++;
        else    pink++;
    }
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            scanf("%d",&map[i][j]);
        }
    }
    color(0,0,N-1,N-1);
    printf("%d\n%d\n",white,pink);
}