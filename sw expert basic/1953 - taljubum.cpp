#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int N,M,R,C,L;
int map[51][51];
int visit[51][51];
int cnt = 0;
int ans = -1;
int mo[4][4] = {{1,2,5,6},{1,3,6,7},{1,2,4,7},{1,3,4,5}};
int dir[7][4] ={{1,1,1,1},{1,0,1,0},{0,1,0,1},{1,1,0,0},{0,1,1,0},{0,0,1,1},{1,0,0,1}};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool canGo(int x,int y,int mode){
    bool flag = false;
    for(int i = 0;i<4;i++){
        if(map[x][y] == mo[mode][i]){
            flag = true;
            break;
        }
    }
    return flag;
}
void dfs(int x,int y,int mode,int depth){
    if(x <0 || x >= N || y <0 || y >=M) return;

    if(visit[x][y] == 1)    return;
    if(map[x][y] == 0)    return;
    

    visit[x][y] = 1;
    cnt++;
    if(depth != L){
        switch(map[x][y]){
            case 0: return;
            case 1:
            if(canGo(x+1,y,3)) dfs(x+1,y,3,depth+1);
            if(canGo(x-1,y,1)) dfs(x-1,y,1,depth+1);
            if(canGo(x,y+1,2)) dfs(x,y+1,2,depth+1);
            if(canGo(x,y-1,4)) dfs(x,y-1,4,depth+1);
            break;
            case 2:
            if(canGo(x-1,y,1)) dfs(x-1,y,1,depth+1);
            if(canGo(x+1,y,3)) dfs(x+1,y,3,depth+1);
            break;
            case 3:
            if(canGo(x,y-1,4)) dfs(x,y-1,4,depth+1);
            if(canGo(x,y+1,2)) dfs(x,y+1,2,depth+1);
            break;
            case 4:
            if(canGo(x-1,y,1)) dfs(x-1,y,1,depth+1);
            if(canGo(x,y+1,2)) dfs(x,y+1,2,depth+1);
            break;
            case 5:
            if(canGo(x,y+1,2)) dfs(x,y+1,2,depth+1);
            if(canGo(x+1,y,3)) dfs(x+1,y,3,depth+1);
            break;
            case 6:
            if(canGo(x,y-1,4)) dfs(x,y-1,4,depth+1);
            if(canGo(x+1,y,3)) dfs(x+1,y,3,depth+1);
            break;
            case 7:
            if(canGo(x,y-1,4)) dfs(x,y-1,4,depth+1);
            if(canGo(x-1,y,1)) dfs(x-1,y,1,depth+1);
            break;
        }
    }
}
void bfs(){
    queue<pair <int, pair<int, int> > >q;
    q.push(make_pair(1,make_pair(R,C)));

    while(!q.empty()){
        cnt++;
        int depth = q.front().first;
        if(L == depth)
            q.pop();
        else
        {
            int x = q.front().second.first;
            int y = q.front().second.second;
            //cout<<x<<" "<<y<<" "<<depth<<endl;
            q.pop();
            visit[x][y] = 1;
            for(int i = 0;i<4;i++){
                if(dir[map[x][y]-1][i] == 1){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || nx >= N || y < 0 || ny >= M) continue;
                    if(visit[nx][ny] == 1 || map[nx][ny] == 0) continue;
                    if(canGo(nx,ny,i)){
                        q.push(make_pair(depth+1,make_pair(nx,ny)));
                        //cout<<"push: "<<nx<<","<<ny<<","<<depth+1<<endl;
                        visit[nx][ny] = 1;
                    }
                }
            }
        }
    }
}
void printVisit(){
    int tp = 0;
    for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                printf("%d ",visit[i][j]);
                if(visit[i][j] == 1){
                    tp++;
                }
            }
            printf("\n");
        }
        cout<<tp<<endl;
}
int main(){
    freopen("input.txt","r",stdin);

    int T;
    scanf("%d",&T);
    for(int t = 1;t<=T;t++){
        scanf("%d%d%d%d%d",&N,&M,&R,&C,&L);
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                scanf("%d",&map[i][j]);
            }
        }
        memset(visit,0,sizeof(visit));
        ans = -1;
        cnt = 0;
        bfs();
        //printVisit();
        printf("#%d %d\n",t,cnt);
    }
}

