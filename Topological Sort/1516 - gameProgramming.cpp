#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    vector<int> vec[501];
    queue<int> q;
    int bTime[501];
    int resTime[501]={};
    int line[501];
    scanf("%d",&N);

    int tp = 0;
    for(int i = 1;i<=N;i++){
        scanf("%d",&bTime[i]);
        //resTime[i] = bTime[i];
        while(true){
            scanf("%d",&tp);
            if(tp == -1) break;
            vec[tp].push_back(i);
            line[i]++;
        }
    }

    for(int i = 1;i<=N;i++){
        if(line[i] == 0){
            q.push(i);
        }
        resTime[i] += bTime[i];
    }

    int cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(int i = 0;i<vec[cur].size();i++){
            int next = vec[cur][i];
            resTime[next] = max(resTime[next],resTime[cur]+bTime[next]);
            if(--line[next] == 0){
                q.push(next);
            }
        }
    }
    for(int i = 1;i<=N;i++){
        printf("%d\n",resTime[i]);
    }

}