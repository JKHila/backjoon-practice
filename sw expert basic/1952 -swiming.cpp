#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int price[5];
int month[12];
int set[12]={};
int ans = 1e9;
int calc(){
    int res = 0;
    for(int i = 0;i<12;i++){
        if(set[i] == 1){
            res += price[set[i]] * month[i];
        }else if(set[i] > 1){
            res += price[set[i]];
        }
        //printf("%d ",set[i]);
    }
    //cout<<endl;
    
    return res;
}
void dfs(int depth){
    if(depth >= 12){
        //cout<<ans<<"."<<calc()<<"."<<depth<<endl;            
        ans = min(ans,calc());
    }else{
        if(month[depth] > 0){
            for(int i = 1;i<=2;i++){
                set[depth] = i;
                dfs(depth+1);
            }
            set[depth] = 3;
            set[depth+1] = 0;
            set[depth+2] = 0;
            dfs(depth+3);
        }else{
            dfs(depth+1);
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int t = 1;t <= T; t++){
        for(int i = 1;i<=4;i++){
            scanf("%d",&price[i]);
        }
        for(int i = 0;i<12;i++){
            scanf("%d",&month[i]);
        }

        memset(set,0,sizeof(set));
        ans = 1e9;
        dfs(0);
        ans = min(ans,price[4]);
        printf("#%d %d\n",t,ans);
    }
}

