#include <cstdio>
#include <queue>
using namespace std;

int N;
int map[101][101];
int wetMap[101][101];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int BFS(){
    int ret= 0;
    queue<pair<int, int> > q;
    int check[101][101]={};

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(check[i][j] == 0 && wetMap[i][j] == 0){
                q.push(make_pair(i, j));
                while (!q.empty())
                {
                    int cx = q.front().first;
                    int cy = q.front().second;
                    q.pop();
                    check[cx][cy] = 1;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if(nx >= 0 && nx <= N-1 & ny >= 0 && ny <= N-1){
                            if (check[nx][ny] == 0 && wetMap[nx][ny] == 0)
                            {
                                q.push(make_pair(nx, ny));
                                check[nx][ny] = 1;
                            }
                        }
                    }
                }
                ret++;
            }
        }
    }
       
    return ret;
    
}


int makeWetMap(int n){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            wetMap[i][j] = 0;
            if(map[i][j] <= n){
                wetMap[i][j] = 1;
            }
        }
    }
}
int main(){
    int top = 0;
    scanf("%d",&N);

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            scanf("%d",&map[i][j]);
            if(top < map[i][j]){
                top = map[i][j];
            }
        }
    }
    int res = 0,tp;
    for(int i = 0;i<=top;i++){
        makeWetMap(i);
        tp = BFS();
        if(res < tp){
            res = tp;
        }
    }
    printf("%d\n",res);
}