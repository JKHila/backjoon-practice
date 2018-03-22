#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int mx = -1e9, mi = 1e9;
int N;
int arr[12];
void dfs(int sum,int sub,int mul,int div,int depth, int res){
    if(depth == N-1){
        mx = max(res,mx);
        mi = min(res,mi);
    }else{
        if(sum > 0) dfs(sum -1,sub,mul,div,depth+1,res + arr[depth+1]);
        if(sub > 0) dfs(sum,sub -1,mul,div,depth+1,res - arr[depth+1]);
        if(mul > 0) dfs(sum,sub,mul-1,div,depth+1,res * arr[depth+1]);
        if(div > 0) dfs(sum,sub,mul,div-1,depth+1,res / arr[depth+1]);
    }
}
int main(){
    int op[12];
    
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%d",&arr[i]);    
    }
    for(int i = 0;i<4;i++){
        scanf("%d",&op[i]);
    }
    dfs(op[0],op[1],op[2],op[3],0,arr[0]);
    printf("%d\n%d\n",mx,mi);
}