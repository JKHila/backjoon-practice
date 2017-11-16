#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int arr[201][201];
int length[201][201];
int N,M;

void BFS(pair<int, int> n){
    priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int, int> > > q;
    length[n.first][n.second] = arr[n.first][n.second];
    q.push(n);

    while(!q.empty()){
        //int cost = q.top().first;
        int x = q.top().first;
        int y = q.top().second;
        q.pop();

        for(int i = 0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx >=0 && nx<=N && ny>=0 && ny<=M){
                if(length[nx][ny] > length[x][y] + arr[nx][ny]){
                    length[nx][ny] = length[x][y] + arr[nx][ny];
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            scanf("%d",&arr[i][j]);
            length[i][j] = 100000000;
        }
    }
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

    BFS(make_pair(x1-1,y1-1));
    printf("%d\n",length[x2-1][y2-1]);
}