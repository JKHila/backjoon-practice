#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > vec[10001];

pair<int, int> getRoot(int n){
    queue<int> q;
    int check[10001] = {};
    int d[10001] = {};
    q.push(n);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        check[cur] = 1;
        
        for(int i = 0;i<vec[cur].size();i++){
            int next = vec[cur][i].first;
            if(check[next] == 0){
                d[next] = d[cur] + vec[cur][i].second; 
                check[next] = 1;
                q.push(next);
            }
        }
    }
    int root = 0;
    int Max = 0;
    for(int i = 1;i<=N;i++){
        if(Max < d[i]){
            Max = d[i];
            root = i;
        }
    }
    return make_pair(root,d[root]);
}

int main(){
    scanf("%d",&N);

    int a,b,c;
    for(int i = 0;i<N-1;i++){
        scanf("%d %d %d",&a,&b,&c);
        vec[a].push_back(make_pair(b,c));
        vec[b].push_back(make_pair(a,c));
    }
    pair<int, int> tmp = getRoot(1);
    
    int rt = tmp.first;
    tmp = getRoot(rt);    

    printf("%d\n",tmp.second);
}