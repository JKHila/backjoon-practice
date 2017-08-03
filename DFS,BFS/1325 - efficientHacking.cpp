#include <cstdio>
#include <queue>
//#include <list>
#include <vector>
using namespace std;

vector<int> ar[10001];
//list<int>::iterator it;    

int BFS(int n){
    queue<int> q;
    int check[10001] = {};
    int ret = 0;

    q.push(n);

    while(!q.empty()){
        int idx = q.front();
        check[idx] = 1;
        q.pop();
        for(int i = 0;i<ar[idx].size();i++){
            if(check[ar[idx][i]] == 0){
                q.push(ar[idx][i]);
                check[ar[idx][i]] = 1;
                ret++;
            }
        }
    }
    return ret;
}

int main(){
    int N,M;
    int res[10001];
    scanf("%d %d",&N,&M);

    int a,b;
    for(int i = 0;i<M;i++){
        scanf("%d %d",&a,&b);
        ar[b].push_back(a);
    }

    int ret,max = 0,idx = 0;
    for(int i = 1;i<=N;i++){
        if(ar[i].size() > 0){
            ret = BFS(i);
            //printf("dd%d\n",ret);
            if(ret > max){
                max = ret;
                idx = 0;
                res[idx++] = i;
            }else if(ret == max){
                res[idx++] = i;                
            }
        }
    }
    for(int i = 0;i<idx;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
}