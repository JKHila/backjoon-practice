#include <cstdio>
using namespace std;
int bottom = 1,top = 6;
int position[4] ={2,3,5,4};//up,right,down,left

int setPosition(int n){ 
    int tpB,tpT;
    switch(n){
        case 2:
            position[0] = bottom;
            position[2] = top;
            bottom = position[3]; 
            top = position[1];
            break;
        case 1:
            position[0] = bottom;
            position[2] = top;
            bottom = position[1]; 
            top = position[3];
            break;
        case 3:
            tpB = bottom;
            tpT = top;
            bottom = position[0]; 
            top = position[2];                    
            position[0] = tpT;
            position[2] = tpB;
            break;
        case 4:
            tpB = bottom;
            tpT = top;
            bottom = position[2]; 
            top = position[0];                    
            position[0] = tpB;
            position[2] = tpT;
            break;
    }
}

int main(){
    int N,M,K,x,y;
    int map[21][21] ={};
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int order;
    int dice[7] = {};
    
    scanf("%d %d %d %d %d",&N,&M,&x,&y,&K);
    int curX = x;
    int curY = y;
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i = 0;i<K;i++){
        scanf("%d",&order);
        setPosition(order);
        curX += dx[order-1];
        curY += dy[order-1];
        //printf("pos:%d %d\n",curX,curY);
        if(map[curX][curY] != 0){
            dice[bottom] = map[curX][curY];
            map[curX][curY] = 0;
            //printf("%d\n",dice[bottom]);
        }else{
            map[curX][curY] = dice[bottom];            
        }
        //printf("%d\n",dice[top]);
        printf("t:%d,b:%d %d\n",top,bottom,dice[top]);
    }
}