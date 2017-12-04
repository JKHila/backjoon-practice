#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
#define INTMAX  2147483647
int N,M,L;
int map[20][20];

using namespace std;
typedef struct node{
    int level;
    int path[10];
    int bound;
}node;
bool operator<(node t, node u){
    return t.bound > u.bound;
}

int bound(node v){
    int ret = 0;
    int k = v.path[v.level];
    bool check[10]={};
    for(int i = 0;i<=v.level;i++){
        check[v.path[i]] = 1;
    }
    for(int i = 0;i<v.level;i++){
        ret += map[v.path[i]][v.path[i+1]];
        //prntf("1ret:%d\n",ret);
    }

    int m = INTMAX;
    for(int i = 1;i<L;i++){
        if(check[i] == 0){
            m = min(m, map[k][i]);
        }
    }
    ret += m;
    //prntf("2ret:%d\n",ret);
    

    for (int j = 1; j <= L; j++)
    {
        if(check[j] == 0){
            bool check2[10];
            for (int i = 1; i < 10; i++)
            {
                if (i != j)
                    check2[i] = check[i];
                else
                    check2[i] = 1;
            }
            check2[0] = 0;        
            int n = INTMAX;
            for (int i = 0; i <= L; i++)
            {
                if (check2[i] == 0)
                {
                    //prntf("!!%d%d\n",j,i);
                    n = min(n, map[i][j]);
                }
            }
            ret += n;
            //prntf("3ret:%d\n",ret);
        }
        
    }
    
    for(int i = 0;i<=v.level;i++){
        //prntf("%d ",v.path[i]);
    }
    //prntf(" ret:%d\n",ret);
    
    return ret;
}

int getLength(node u){
    int ret = 0;
    //prntf("final:");
    for(int i = 0;i<L;i++){
        ret += map[u.path[i]][u.path[i+1]];
        //prntf("%d ",u.path[i]);
    }
    ret += map[u.path[L]][0];
    //prntf("%d len:%d\n",u.path[L],ret);
    
    return ret;
}
int tsp(){
    priority_queue<node> q;
    node u,v;

    v.level = 0;
    v.path[v.level] = 0;
    v.bound = bound(v);
    int minLen = INTMAX;
    
    q.push(v);

    while(!q.empty()){
        bool check[10]={};    
        v = q.top();
        ////prntf("bound: %d\n",v.bound);
        q.pop();
        for(int i = 0;i<=v.level;i++){
            check[v.path[i]] = 1;
            ////prntf("path %d\n",v.path[i]);
        }
        ////prntf("\n");
        if(v.bound < minLen){
            u.level = v.level +1;
            for(int i = 1;i<=L;i++){
                if(check[i] == 0){
                    for(int j = 0;j<=u.level;j++){
                        u.path[j] = v.path[j];
                    }
                    u.path[u.level] = i;
                    if(u.level == L - 1){
                        for(int k = 1;k <= L;k++){
                            if(check[k] == 0 && k != i){
                                u.path[L] = k;
                            }
                        }
                        minLen = min(minLen,getLength(u));
                    }else{
                        u.bound = bound(u);
                        if(u.bound < minLen)    q.push(u);
                    }
                }
            }
        }
    }
    return minLen;
}
int getDistance(pair<int, int> n, pair<int, int> m){
    return abs(n.first-m.first) + abs(n.second - m.second);
}
int main(){
    int x,y;
    pair<int, int> pos[10];
    scanf("%d%d%d%d%d",&N,&M,&pos[0].first,&pos[0].second,&L);
    for(int i = 1;i<=L;i++){
        scanf("%d%d",&x,&y);
        pos[i] = make_pair(x,y);
    }
    
    for(int i = 0;i<=L;i++){
        for(int j = 0;j<=L;j++){
            map[i][j] = getDistance(pos[i],pos[j]);
            ////prntf("%d ",map[i][j]);
        }    
        ////prntf("\n");
    }
    if(L == 1){
        printf("The shortest path has length %d \n",getDistance(pos[0],pos[1]));
    }else
        printf("The shortest path has length %d \n",tsp());
}