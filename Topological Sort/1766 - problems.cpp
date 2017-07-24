#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N,M;
    vector<int> vec[32001];
    priority_queue<int, vector<int>, greater<int> > q;
    int line[32001];
    vector<int> res;

    scanf("%d%d",&N,&M);

    int a,b;
    for(int i = 0;i<M;i++){
        scanf("%d%d",&a,&b);
        vec[a].push_back(b);
        line[b]++;
    }

    for(int i = 1;i<=N;i++){
        if(line[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.top();
        q.pop();
        res.push_back(cur);
        /*for(int i = 0;i<N;i++){
            printf("%d ",res[i]);
        }
        printf("\n");*/
        for(int i = 0;i<vec[cur].size();i++){
            int next = vec[cur][i];
            if(--line[next] == 0){
                q.push(next);
                //res.push_back(next);        
            }
        }
    }

    for(int i = 0;i<N;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
}