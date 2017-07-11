#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int N,M;
    int map[101][101];
    int check[101][101];
    char ch[101];
    queue<pair<int, int> > q;
    scanf("%d %d",&N,&M);

    for(int i = 0;i<N;i++){
        scanf("%s",ch);
        for(int j = 0;j<M;j++){
            check[i][j] = 0;
            map[i][j] = ch[j] - 48;
        }
    }
    q.push(make_pair(0,0));
    int x,y,nx,ny;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(map[nx][ny] == 1 && check[nx][ny] == 0){
                check[nx][ny] = check[x][y] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    printf("%d\n",check[N-1][M-1]+1);

}