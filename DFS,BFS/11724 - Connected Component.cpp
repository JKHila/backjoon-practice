#include <cstdio>
using namespace std;
int N,M;
int map[1001][1001]={};
int check[1001];
void DFS(int n){
    check[n] = 1;
    for(int i = 1;i<=N;i++){
        if(check[i] == 0 && map[n][i] == 1){
            DFS(i);
            check[i] = 1;    
        }
    }
}
int main(){
    int x,y,ans=0;
    scanf("%d%d",&N,&M);
    for(int i = 0;i<M;i++){
        scanf("%d%d",&x,&y);
        map[x][y] = 1;
        map[y][x] = 1;
    }
    for(int i = 1;i<= N;i++){
        if(check[i] == 0){
            DFS(i);
            ans++;
        }
    }
    printf("%d\n",ans);
}