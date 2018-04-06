#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N= 0,M=0;
int map[21][21]={};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void printV(){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            //cout<<visit[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int bfs(int x,int y){
    int visit[21][21]= {0};
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    visit[x][y] = 1;
    
    int cnt = map[x][y];
    int K =0;
    int ans = cnt;
    int cur = 1;
    //memset(visit,0,sizeof(visit));
    
    while(!q.empty()){
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            if(nx < 0 || nx >= N || ny <0 || ny>=N) continue;
            if(visit[nx][ny]) continue;
            K = visit[nx][ny] = visit[fx][fy] + 1;
            //visit[nx][ny] = 1;
            q.push(make_pair(nx,ny));
            if(map[nx][ny] == 1) cnt++;
        }
        if(cnt*M - (K*K +(K-1)*(K-1)) >= 0){
            ans = cnt;
        }
    }
    //printV();
    return ans;
}
int main(){
    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int t = 1; t<= T; t++){
        int ans = -1;
        cin >> N >> M;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                cin >> map[i][j];
            }
        }
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                ans = max(ans,bfs(i,j));
            }
        }

        cout<<"#"<<t<<" "<<ans<<endl;
    }
}