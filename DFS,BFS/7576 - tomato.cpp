#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int box[1001][1001];
    int check[1001][1001];
    queue<pair<int,int> > q;

    int N,M;
    scanf("%d %d",&N,&M);
    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
            check[i][j] = -1;
            scanf("%d",&box[i][j]);
            if(box[i][j] > 0){
                check[i][j] = 0;
                q.push(make_pair(i,j));
            }
        }
    }

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int nx,ny;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            nx = x+dx[i];
            ny = y+dy[i];
            if(box[nx][ny] != -1  && check[nx][ny] == -1){
                q.push(make_pair(nx,ny));
                check[nx][ny] = check[x][y] + 1;
            }
        }
    }
    int res = 0 ;
    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
            if(box[i][j] == 0 && check[i][j] == -1) {printf("-1\n"); return 0;}
            if(check[i][j] > res){
                res = check[i][j];
            }
        }
    }
    printf("%d\n",res);
}