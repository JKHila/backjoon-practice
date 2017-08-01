#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> vec[100001];
int dp[100001][5];

void BFS(int n){
    queue<int> q;
    int check[100001] = {};
    q.push(n);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        check[cur] = 1;

        for(int i = 0;i<vec[cur].size();i++){
            int next = vec[cur][i];
            if(check[next] == 0){
                check[next] = 1;
                q.push(next);
                dp[cur][1] += min(dp[next][2],min(dp[next][3],dp[next][4]));
                dp[cur][2] += min(dp[next][1],min(dp[next][3],dp[next][4]));
                dp[cur][3] += min(dp[next][1],min(dp[next][2],dp[next][4]));
                dp[cur][4] += min(dp[next][1],min(dp[next][2],dp[next][3]));
                printf("%d %d %d %d %d %d\n",cur,next,dp[cur][1],dp[cur][2],dp[cur][3],dp[cur][4]);
            }
        }
    }

}

int main(){
    int N;
    scanf("%d",&N);

    int a,b;
    for(int i = 0;i<N-1;i++){
        scanf("%d %d",&a,&b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<5;j++){
            dp[i][j] = j;
        }
    }

    BFS(1);

    int res = dp[1][1];
    for(int i = 2;i<5;i++){
        res = min(res,dp[1][i]);
    }
    printf("%d\n",res);
}