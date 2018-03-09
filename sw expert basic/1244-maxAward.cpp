#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
char ch[7];

int check[1000000];
int N;
int len,res=0;
void dfs(int idx,int depth){
    int tp = 0;
    for(int i = 0;i<len;i++){
        tp += pow(10,len - i - 1)*(ch[i]-'0');
    }
    if(depth == N){
        res = max(res,tp);
        return;
    }
    if(check[tp]==1)return;
    check[tp] = 1;

    for(int i = idx;i<len;i++){
        for(int j = i+1;j<len;j++){
            swap(ch[i],ch[j]);
            dfs(i,depth+1);
            swap(ch[j],ch[i]);
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i = 1;i<=T;i++){
        scanf("%s %d",ch,&N);
        len = strlen(ch);
        dfs(0,0);
       
        printf("#%d %d\n",i,res);
        memset(check,0,sizeof(check));
        res = 0;
    }
}