#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int N,M,K;
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};
int ans = 0;
typedef struct node{
    int x;
    int y;
    int n;
    int d;
}node;
vector<node> vec;
void solve(){
    int map[100][100]={};
    ans = 0;
    //M번 반복
    for(int i = 0;i<M;i++){
        //각 미생물 당 계산
        for(int j = 0;j<vec.size();j++){
            if(vec[j].n == 0) continue;
            //이동        
            vec[j].x += dx[vec[j].d];
            vec[j].y += dy[vec[j].d];
            //맵에 체크
            map[vec[j].x][vec[j].y] +=1;
            //맵 끝이면 방향 변경, 미생물 수 반으로
            if(vec[j].x == 0 || vec[j].x == N-1 || vec[j].y == 0 || vec[j].y == N-1){
                switch(vec[j].d){
                    case 1: vec[j].d = 2;break;
                    case 2: vec[j].d = 1;break;
                    case 3: vec[j].d = 4;break;
                    case 4: vec[j].d = 3;
                }
                vec[j].n /= 2;                
            }
        }
        //겹치는 미생물 검사
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(map[i][j] > 1){
                    int sum = 0;
                    int mxNode = -1;
                    int mxNum = -1;
                    //해당 맵에 있는 셀 전부 검사
                    for(int k = 0;k<vec.size();k++){
                        if(vec[k].n == 0) continue;
                        if(vec[k].x == i && vec[k].y == j){
                            sum += vec[k].n;
                            if(mxNum < vec[k].n){
                                mxNum = vec[k].n;
                                mxNode = k;                          
                            }
                            vec[k].n = 0;
                        }
                    }
                    //제일 큰 미생물 군집에 몰빵
                    vec[mxNode].n = sum;
                }
                map[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < vec.size(); j++)
    {
        if (vec[j].n == 0)
            continue;
        ans += vec[j].n;
    }
}
int main(){
    freopen("input.txt","r",stdin);
    int T;
    cin >> T;
    int x,y;
    for(int t = 1; t<= T;t++){
        cin >> N >> M >> K;
        for(int i = 0; i < K; i++){
            node nd;
            cin >> nd.x >> nd.y >> nd.n >> nd.d;
            vec.push_back(nd);
        }
        solve();
        cout<<"#"<<t<<" "<<ans<<endl;
        vec.clear();
    }
}