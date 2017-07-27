#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> vec[1001];
int dCheck[1001] = {};


void DFS(int n){
    printf("%d ",n);
    dCheck[n] = 1;
    sort(vec[n].begin(),vec[n].end());
    
    for(int i = 0;i<vec[n].size();i++){
        int next = vec[n][i];
        if(dCheck[next] == 0){
            dCheck[next] = 1;
            DFS(next);
        }
    }
}

void BFS(int n){
    queue<int> q;
    int check[1001] = {};

    q.push(n);

    while(!q.empty()){
        int cur = q.front();
        printf("%d ",cur);
        q.pop();
        check[cur] = 1;
        sort(vec[cur].begin(),vec[cur].end());
        for(int i = 0;i<vec[cur].size();i++){
            int next = vec[cur][i];
            if(check[next] == 0){
                check[next] = 1;
                q.push(next);
            }
        }
    }
}

int main(){
    int N,M,V;
    scanf("%d %d %d",&N,&M,&V);

    int a,b;
    for(int i = 0;i<M;i++){
        scanf("%d %d",&a,&b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    DFS(V);printf("\n");
    BFS(V);printf("\n");
    
}