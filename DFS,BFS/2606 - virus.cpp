#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int N,M,res = 0;
    int com[101][101];
    int check[101] = {};
    queue<int> q;
    scanf("%d",&N);
    scanf("%d",&M);

    int a,b;
    for(int i = 0;i<M;i++){
        scanf("%d %d",&a,&b);
        com[a][b] = com[b][a] = 1;
    }
    q.push(1);

    int cur;
    check[1] = 1;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(int i = 1;i<=N;i++){
            if(com[cur][i] == 1 && check[i] == 0){
                check[i] = 1;
                q.push(i);
                res++;
            }
        }
    }
    printf("%d\n",res);

}