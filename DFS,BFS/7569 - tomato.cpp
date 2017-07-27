#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int box[101][101][101];
    int check[101][101][101];
    queue<pair<int, pair<int,int> > > q;

    int N,M,H;
    scanf("%d %d %d",&N,&M,&H);
    for(int k = 0;k<H;k++){
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                check[k][i][j] = -1;
                scanf("%d",&box[k][i][j]);
                if(box[k][i][j] > 0){
                    check[k][i][j] = 0;
                    q.push(make_pair(k,make_pair(i,j)));
                }
            }
        }
    }

    int dx[6] = {1,0,0,-1,0,0};
    int dy[6] = {0,0,1,0,0,-1};
    int dz[6] = {0,1,0,0,-1,0};
    int nx,ny,nz;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        q.pop();
        for(int i = 0;i<6;i++){
            nx = x+dx[i];
            ny = y+dy[i];
            nz = z+dz[i];
            if(box[nx][ny][nz] != -1  && check[nx][ny][nz] == -1){
                q.push(make_pair(nx,make_pair(ny,nz)));
                check[nx][ny][nz] = check[x][y][z] + 1;
            }
        }
    }
    int res = 0 ;
    for(int k = 0;k<H;k++){
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(box[k][i][j] == 0 && check[k][i][j] == -1) {printf("-1\n"); return 0;}
                if(check[k][i][j] > res){
                    res = check[k][i][j];
                }
            }
        }
    }
    printf("%d\n",res);
}