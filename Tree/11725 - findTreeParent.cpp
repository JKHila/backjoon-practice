#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    vector<int> vec [100001];
    queue<int> q;
    int p[100001];
    int check[100001];
    scanf("%d",&N);

    int a,b;
    for(int i = 0;i<N-1;i++){
        scanf("%d%d",&a,&b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    q.push(1);

    while(!q.empty()){
        int cur = q.front();
        check[cur] = 1;
        q.pop();
        for(int i = 0;i<vec[cur].size();i++){
            int next = vec[cur][i];
            if(check[next] == 0){
                p[next] = cur;
                q.push(next);
                check[next] = 1;
            }
        }
    }
     for(int i = 2;i<=N;i++){
       printf("%d\n",p[i]);
    }
}