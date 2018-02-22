#include <cstdio>
#include <queue>
using namespace std;
int map[100][100] = {};
queue<pair<int, int> > q;
int eX,eY;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
bool BFS(){
    bool flag = false;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx <100 && ny >= 0 && ny < 100){
                if(nx == eX && ny == eY)
                    flag = true;
                if(map[nx][ny] == 0){
                    q.push(make_pair(nx,ny));
                    map[nx][ny] = 1;
                }
            }
        }
    }
    return flag;
}
int main(){
    int a,T = 1;
    while(T <= 10){
        scanf("%d",&a);
        for(int i = 0;i<100;i++){
            for(int j = 0;j<100;j++){
                scanf("%1d",&map[i][j]);
                if(map[i][j] == 2){
                    q.push(make_pair(i,j));
                }else if(map[i][j] == 3){
                    eX = i;
                    eY = j;
                }
            }
        }
        printf("#%d %d\n",T++,BFS());
    }/* 
    for(int i = 0;i<16;i++){
        for(int j = 0;j<16;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    } */
}