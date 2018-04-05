#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
int map[21][21]={};
int cafe[101];
int visit[21][21]={};
int sx,sy;
int ans = -1;
int cnt = 0;

void printVisit(){
    for (int i = 1; i<=N; i++) {
			for (int j = 1; j <= N; j++) {
                printf("%d ",visit[i][j]);
			}
            printf("\n");
		}
        cout<<endl;
}
void dfs(int x,int y, int mode){
    //visit[x][y] += 1;
    //if(x < 0 || x >= N || y < 0 || y >=N) return;
    cafe[map[x][y]] += 1;
    visit[x][y] +=1;
    cnt++;    
    
    if(mode == 4 && visit[x][y] == 2){
        ans = max(ans,cnt-1);
        //printVisit();
    }else{
        if(mode == 0){
            if(!cafe[map[x+1][y+1]] && map[x][y] != 0) dfs(x+1,y+1,1);
        }else if(mode == 1){
            if(!cafe[map[x+1][y-1]] && map[x+1][y-1] != 0) dfs(x+1,y-1,2);
            if(!cafe[map[x+1][y+1]] && map[x+1][y+1] != 0) dfs(x+1,y+1,1);
        }else if(mode == 2){
            if(!cafe[map[x-1][y-1]] && map[x-1][y-1] != 0) dfs(x-1,y-1,3);
            if(!cafe[map[x+1][y-1]] && map[x+1][y-1] != 0) dfs(x+1,y-1,2);
        }else if(mode == 3){
            if(!cafe[map[x-1][y-1]] && map[x-1][y-1] != 0) dfs(x-1,y-1,3);
            if(sx == x-1 && sy == y+1){
                dfs(x-1,y+1,4);
            }
            else if(!cafe[map[x-1][y+1]] && map[x-1][y+1] != 0) dfs(x-1,y+1,4);
        }else{
            if(sx == x-1 && sy == y+1){
                dfs(x-1,y+1,4);
            }
            else if(!cafe[map[x-1][y+1]] && map[x-1][y+1] != 0) dfs(x-1,y+1,4);
        }
    }
    cnt--;
    cafe[map[x][y]] -= 1;
    visit[x][y] -=1;
    
}
int main() {
	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (int i = 1; i<=N; i++) {
			for (int j = 1; j <=N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
        ans = -1;
        cnt = 0;
		for (int i = 1; i < N; i++) {
			for (int j = 2; j < N; j++) {
                sx = i;
                sy = j;
                memset(visit,0,sizeof(visit));
                dfs(i,j,0);
			}
		}
        printf("#%d %d\n",t,ans);
	}
}