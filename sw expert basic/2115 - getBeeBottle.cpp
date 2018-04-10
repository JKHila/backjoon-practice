#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int N,M,C;
int map[11][11];
int beeBottle[6];
bool check[6];
int mx = -1;
void calc(int x,int y){
    int ret = 0;
    int amount = 0;
    for(int i = 0;i<M;i++){
        if(check[i] == 1){
            ret += pow(map[x][y+i],2);
            amount += map[x][y+i];
        }
    }
    if(amount <= C)
        mx = max(mx,ret);
}
void dfs(int depth,int x,int y){
    if(depth == M){
        calc(x,y);
    }else{
        check[depth] = true;
        dfs(depth+1);
        check[depth] = false;
        dfs(depth+1);
    }
}
int checkF(int x,int y){
    int ret = 0;
    int amount = 0;
    bool flag = true;
    if(y+M-1 >= N) return -1;

    for(int i = y;i<y+M;i++){
        if(map[x][i] != -1){            
            ret += pow(map[x][i],2);
            amount += map[x][i];
        }else{
            flag = false;
            break;
        }
    }
    if(flag){
        //cout<<"amount:"<<amount<<" ret:"<<ret<<" x:"<<x<<" y:"<<y<<" y+M-1:"<<y+M-1<<endl;    
        if(amount > C){
            mx = -1;
            dfs(0,x,y);
            return mx;
        } 
        return ret;
    }
    else return -1;
}
void pm(){
    for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                printf("%d ",map[i][j]);
            }
            printf("\n");
        }
        cout<<endl;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t = 1;t<=T;t++){
        scanf("%d%d%d",&N,&M,&C);
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                scanf("%d",&map[i][j]);
            }
        }
        int res = 0;
        int mxBot;
        int x,y;
        for(int k = 0;k<2;k++){
            mxBot = -1;
            for(int i = 0;i<N;i++){
                for(int j = 0;j<N;j++){
                    int tp = checkF(i,j);
                    if(tp > 0 && mxBot < tp){
                       mxBot = tp;
                       x = i; y = j;
                    }
                }
            }
            for(int i = y;i<y+M;i++){
                map[x][i] = -1;
            }
            //pm();
            res += mxBot;
        }
        printf("#%d %d\n",t,res);
    }
}