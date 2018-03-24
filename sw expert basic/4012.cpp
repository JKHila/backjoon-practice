#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int N;
int map[16][16];
int ans = 1e9;
bool check[16]={};
int getS(vector<int>& vec){
    int res = 0;
    for(int i = 0;i<N/2;i++){
        for(int j = 0;j<N/2;j++){
            if(i != j) res += map[vec[i]][vec[j]];
        }
    }
    return res;
}

int getRes(){
    vector<int> a;
    vector<int> b;

    for(int i = 0;i<N;i++){
        if(check[i]) a.push_back(i);
        else b.push_back(i);
    }

    return fabs(getS(a) - getS(b));
    
}
void dfs(int idx,int depth){
    check[idx] = true;

    if(depth == N/2){
        ans = min(ans,getRes());
    }else{
        for(int i = idx+1;i<N;i++){
           dfs(i,depth+1);
        }
    }

    check[idx] = false;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t = 1;t <= T;t++){
        scanf("%d",&N);
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                scanf("%d",&map[i][j]);
            }        
        }
        dfs(0,1);
        printf("#%d %d\n",t,ans);
        ans = 1e9;
        memset(check,0,sizeof(check));
    }
}