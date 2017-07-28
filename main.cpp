#include <cstdio>
#include <algorithm>
using namespace std;

int N,block = 0,res = 999;
int map[55][55];
int check[55][55];

int dx[4] ={-1,1,0,0};
int dy[4] ={0,0,1,-1};
void DFS(int x,int y){
    check[x][y] = 1;
    //printf("%d %d\n",x,y);
    if(x == N && y == N){
        res = min(res,block);
        block = 0;
        //printf("e%d\n",block);
        return;
    }
    else if(map[x][y] == 0){
        block++;
        //printf("dd%d\n",block);
    }
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        //printf("%d %d\n",nx,ny);
        if(check[nx][ny] == 0){
            if(nx > 0 && nx <= N && ny > 0 && ny <=N){
                DFS(nx,ny);
            }
        }
    }
}

int main(){
    scanf("%d",&N);

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    DFS(1,1);
    printf("%d\n",res);
}