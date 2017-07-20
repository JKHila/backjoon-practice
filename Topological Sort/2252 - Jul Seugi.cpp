#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int N,M;
    vector<int> vec[32001];
    queue<int> q;
    queue<int> res;
    int line[32001];
    scanf("%d %d",&N,&M);

    int a,b;
    for(int i = 0;i<M;i++){
        scanf("%d %d",&a,&b);

        vec[a].push_back(b);
        line[b]++;
    }

    for(int i = 1;i<=N;i++){
        //printf("line%d\n",line[i]);
        if(line[i] == 0){
            q.push(i);
        }
    }

    int cur;
    while(!q.empty()){
        cur = q.front();
        res.push(cur);
        q.pop();
        for(int i = 0;i<vec[cur].size();i++){
            line[vec[cur][i]]--;
            if(line[vec[cur][i]] == 0){
                q.push(vec[cur][i]);
            }
        }
    }


    while(!res.empty()){
        printf("%d ",res.front());
        res.pop();
    }
    printf("\n");
}