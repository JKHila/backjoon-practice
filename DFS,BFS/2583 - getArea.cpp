#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int map[101][101]={};
int check[101][101]={};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int M,N,K;

int BFS(pair<int, int> n){
    int area=0;
    queue<pair<int,int> > q;
    q.push(n);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        check[x][y] = 1;
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < M && ny >=0 && ny < N){
                if(check[nx][ny] == 0 && map[nx][ny] == 0){
                    check[nx][ny] = 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
        area++;
    }
    return area;
}
int main(){
    int ans= 0;
    priority_queue<int,vector<int>,greater<int> > q;
    scanf("%d%d%d",&M,&N,&K);
    int x1,x2,y1,y2;
    for(int i = 0;i<K;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int j = x1;j<x2;j++){
            for(int k = y1;k<y2;k++){
                map[k][j] = 1;
            }
        }
    }
    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
            if(map[i][j] == 0 && check[i][j] == 0){
                q.push(BFS(make_pair(i,j)));
                ans++;
            }
        }
    }
    printf("%d\n", ans);

    while (!q.empty())
    {
        printf("%d ", q.top());
        q.pop();
    }
    printf("\n");
}