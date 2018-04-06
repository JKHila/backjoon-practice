#include <iostream>
#include <algorithm>
using namespace std;
int D,W,K;
int map[14][21]={};
int drug[14]={};
int ans = 1e9;
bool isFind = false;
void check(int ret){
    int cur,cnt = 0;
    bool flag[21] = {false,};
    int tmap[14][21];

    //약품 투여
    for(int i = 0;i<D;i++){
        if(drug[i]){
            for(int j = 0;j<W;j++){
                tmap[i][j] = drug[i] - 1;
            }
        }else{
            for(int j = 0;j<W;j++){
               tmap[i][j] = map[i][j];
            }
        }
    }
    //기준 통과 검사
    for(int i = 0;i < W;i++){
        cur = tmap[0][i];
        cnt = 1;
        for(int j = 1;j<D;j++){
            if(tmap[j][i] == cur) cnt++;
            else{ cur = tmap[j][i];  cnt = 1;}

            if(cnt == K) flag[i] = true;
        }
        if(!flag[i]) return;
    }
    
    ans = min(ans,ret);
}
void dfs(int depth){
        if(depth == D){
            int ret = 0;
            //약 갯수 카운트
            for(int i = 0;i<D;i++){
                if(drug[i]) ret++;   
            }
            //갯수 작을때만 호출
            if(ret < ans)
                check(ret);
        }else{
            for(int i = 0;i<3;i++){
                drug[depth] = i;
                dfs(depth+1);
            }
        }
}
int main(){
    freopen("input.txt","r",stdin);
    int T;
    cin >> T;
    for(int t = 1;t<=T;t++){
        ans = 1e9;
        isFind = false;
        cin >> D >> W >> K;
        for(int i = 0;i < D;i++){
            for(int j = 0;j<W;j++){
                cin >> map[i][j];
            }
        }
        dfs(0);
        cout<<"#"<<t<<" "<<ans<<endl;
    }
}