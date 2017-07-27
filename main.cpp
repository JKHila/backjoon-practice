#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N,M;

int b[301][301];
int isB[301][301];
vector<pair<int, int> > vec;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int getMelt(int x,int y){
    int ret = 0;
    for(int i = 0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(isB[nx][ny] == 0){
            ret++;
        }
    }
    return ret;
}
int getDebris(){
    int check[301][301]={};
    queue<pair<int, int> > q;
    int ret = 0;

    
    for(int i = 0;i<vec.size();i++){ //vec안에 있는 좌표를 큐에 넣으면서 검사
        int x = vec[i].first;
        int y = vec[i].second;
        if(check[x][y] == 0){
            q.push(make_pair(x,y));

            while(!q.empty()){
                int cX = q.front().first;
                int cY = q.front().second;
                q.pop();
                check[cX][cY] = 1;
                for(int j = 0;j<4;j++){
                    int nx = cX + dx[j];
                    int ny = cY + dy[j];
                    if(check[nx][ny] == 0){
                        check[nx][ny] = 1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
            ret++;
        }
    }
    return ret;
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            scanf("%d",&b[i][j]);
            if(b[i][j] > 0){
                isB[i][j] = 1;
                vec.push_back(make_pair(i,j));
            }
        }
    }
        printf("%lu\n",vec.size());
    
    int debris = 1,res = 0;
    //while(debris == 1){
        for(int i = 0;i<vec.size();i++){ //빙산 녹음 처리
            int x = vec[i].first;
            int y = vec[i].second;
            b[x][y] -= getMelt(x,y);
            if(b[x][y] < 0) b[x][y] = 0;
        }
        for(int i = 0;i<vec.size();i++){ //isB 정리
            int x = vec[i].first;
            int y = vec[i].second;
            if(b[x][y] == 0){
                isB[x][y] = 0;
                vec.erase(vec.begin()+i);            
            }
        }
        printf("%lu\n",vec.size());
        debris = getDebris();
        res++;
    //}
    printf("%d\n",res);    
    
    /*for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");    
    }
        printf("\n");    
    for(int i = 0;i<vec.size();i++){
            int x = vec[i].first;
            int y = vec[i].second;
    printf("%d %d\n",x,y);
    }*/
}