#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,K;
int map[9][9];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ans = -1;
void dfs(int x,int y,int depth){
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(map[nx][ny] < map[x][y])
            dfs(nx,ny,depth+1);
    }
    ans = max(ans,depth);
}
int main(){
    freopen("input.txt","r",stdin);
    int T;
    cin >> T;
    vector<pair<int,int> > vec;
    for(int t = 1; t<=T;t++){
        int MAX = -1;
        ans = -1;
        cin >> N >> K;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                cin >> map[i][j];
                MAX = max(MAX,map[i][j]);
            }
        }
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(map[i][j] == MAX){
                    vec.push_back(make_pair(i,j));
                }
            }
        }
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                for(int k = 0;k <=K;k++){
                    map[i][j]-=k;
                    for(int l = 0;l < vec.size();l++){
                        dfs(vec[l].first,vec[l].second,1);
                    }
                    map[i][j]+=k;
                }
            }
        }
        cout<<"#"<<t<<" "<<ans<<endl;
        vec.clear();
    }
}