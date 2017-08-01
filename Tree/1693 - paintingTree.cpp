#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
vector<int> vec[100001];
int dp[100001][20];
int check[100001];
int l;

void DFS(int n){
    check[n] = 1;
    for(int i = 1;i<=l;i++){
        dp[n][i] = i;
    }

    for(int i = 0;i<vec[n].size();i++){
        int cur = vec[n][i];
        if(check[cur] == 0){
            check[cur] = 1;
            DFS(cur);
            
            for(int j = 1;j<=l;j++){
                int mini = INT_MAX;            
                for(int k = 1;k<=l;k++){
                    if(j != k){
                        mini = min(mini,dp[cur][k]);
                    }
                }
                dp[n][j] += mini;            
            }
        }
    }
}

/*void BFS(int n)
{
    queue<int> q;
    int check[100001] = {};
    q.push(n);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        check[cur] = 1;

        for (int i = 0; i < vec[cur].size(); i++)
        {
            int next = vec[cur][i];
            if (check[next] == 0)
            {
                check[next] = 1;
                q.push(next);


                for (int j = 1; j <= l; ++j)
                {
                    int mini = INT_MAX;
                 
                    for(int k = 1 ; k <= l ; ++k)
                    {
                        if(j != k)
                        {
                            mini = min(mini, dp[next][k]);
                        }   
                    }
                    dp[cur][j] += mini;
                }
            }
        }
    }
}*/

int main()
{
    int N;
    scanf("%d", &N);

    l = log2(N);
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    DFS(1);

    int res = dp[1][1];
    for (int i = 2; i <= l; i++)
    {
        res = min(res, dp[1][i]);
    }
    printf("%d\n", res);
}