#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int mag[4][8];
int isRotate[4]={};

void rotateMag(int num, int dir){
    if(dir == 1){
        int tp = mag[num][7];
        for(int i = 7;i>0;i--){
            mag[num][i] = mag[num][i-1];
        }
        mag[num][0] = tp;
        //printf("rot: %d %d\n",num,dir);
    }else{
        int tp = mag[num][0];
        for(int i = 0;i<7;i++){
            mag[num][i] = mag[num][i+1];
        }
        mag[num][7] = tp;
        //printf("urot: %d %d\n",num,dir);
        
    }
}
void dfs(int num,int rotDir){
    //printf("dfs: %d %d\n",num,rotDir);
    
    if(isRotate[num] != 0) return;
   
    isRotate[num] = rotDir;
    //printf("??:%d %d\n",num,rotDir);
    if(num != 3 && mag[num][2] != mag[num+1][6]){
        //isRotate[num+1] = rotDir*-1;
        dfs(num+1,rotDir*-1);
    }

    //printf("dfs2:%d %d %d\n",num,mag[num][6],mag[num-1][2]);
    if(num != 0 && mag[num][6] != mag[num-1][2]){
        //isRotate[num-1] = rotDir*-1;
        dfs(num-1,rotDir*-1);
    }
}
void printMag(){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<8;j++){
            printf("%d ",mag[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t = 1;t <= T;t++){
        int N;
        scanf("%d",&N);
        for(int i = 0;i<4;i++){
            for(int j= 0;j<8;j++){
                scanf("%d",&mag[i][j]);
            }
        }
        for(int i = 0;i<N;i++){
            int magNum,dir;
            scanf("%d %d",&magNum,&dir);
            //isRotate[magNum-1] = dir;
            dfs(magNum-1,dir);

            for(int j = 0;j<4;j++){
                //printf("is: %d\n",isRotate[j]);
                if(isRotate[j] != 0){
                    rotateMag(j,isRotate[j]);
                }
            }
            memset(isRotate,0,sizeof(isRotate));

            //printMag();
            //printf("\n");
        }
        int ans  = 0;
        for(int i = 0;i<4;i++){
            if(mag[i][0] == 1)
                ans += pow(2,i);
        }
        printf("#%d %d\n",t,ans);
    }
}