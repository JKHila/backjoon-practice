#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
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
bool getDebris(){
    int check[301][301]={};
    queue<pair<int, int> > q;

    int x = vec[0].first;
    int y = vec[0].second;
    q.push(make_pair(x,y)); 

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        check[x][y] = 1;
        for(int i = 0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check[nx][ny] == 0 && isB[nx][ny] == 1)
            {
                check[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    for(int i = 0;i<vec.size();i++){ //BFS돌린 후 vec안에 있는 좌표중 검사되지 않은 좌표가 하나라도 있으면 2덩어리 이상 빙하 발생
        int x = vec[i].first;
        int y = vec[i].second;
        if(check[x][y] == 0){
            return false;
        }
    }
    return true;
}

void showB(){
    printf("\n"); 
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");    
    }
}

void showIsB(){
    printf("\n"); 
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            printf("%d ",isB[i][j]);
        }
        printf("\n");    
    }
}

void showVec(){
    printf("%lu:\n",vec.size());
    for(int i = 0;i<vec.size();i++){
        printf("%d %d\n",vec[i].first,vec[i].second);
    }
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if (i == 0 || i == N - 1 || j == 0 || j == M - 1) b[i][j] = 0;                        
            scanf("%d",&b[i][j]);
            if(b[i][j] > 0){
                isB[i][j] = 1;
                vec.push_back(make_pair(i,j));
            }
        }
    }
        //showIsB();
    
    bool debris = getDebris();
    int res = 0;
    vector<pair<int,int> >::iterator it;
    
    while(debris){
        for(int i = 0;i<vec.size();i++){ //빙산 녹음 처리
            int x = vec[i].first;
            int y = vec[i].second;
            b[x][y] -= getMelt(x,y);
            if(b[x][y] <= 0) b[x][y] = 0;
        }
        //showB();
        int size = vec.size();
        for(it = vec.begin(); it != vec.end(); ){ //isB 정리
            int x = it->first;
            int y = it->second;
            if(b[x][y] <= 0){
                isB[x][y] = 0;
                it = vec.erase(it);            
            }else{
                it++;
            }
        }
        //showIsB();
        //showVec();
        debris = getDebris();
        if(vec.empty()){
            printf("0\n");return 0;
        }
        res++;
    }
    printf("%d\n",res);    
    
    /*   
    */
}