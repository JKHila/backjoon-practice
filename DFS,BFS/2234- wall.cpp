#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int dy[4] ={1,0,-1,0};
int dx[4] ={0,1,0,-1};
int map[51][51]={0};
int check[51][51]={0};
int N,M;
int checkNum = 1;
int* getBinary(int n){
    static int tp[4];
    for(int i = 0;i<4;i++){
        tp[i] = 0;
    }
    int i = 3;
    while(true){
        if(n%2)
            tp[i--] = 1;
        else
            tp[i--] = 0;
        n /= 2;
        if(n == 0){
            break;
        }
    }
    return tp;
}
int BFS(int y,int x){
    int *wall;
    queue<pair<int,int > > q;
    int roomSize = 0;
    q.push(make_pair(y,x));
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        wall = getBinary(map[y][x]); 
        q.pop();                
        check[y][x] = checkNum;
        for(int i = 0;i<4;i++){
            if(wall[i] == 0){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >=0 && nx <= N-1 && ny >=0 && ny <=M-1){
                    if(check[ny][nx] == 0){
                        q.push(make_pair(ny,nx));
                        check[ny][nx] = checkNum;
                    }
                }
            }
        }
        roomSize++;
    }
    return roomSize;
}
int main(){
    int roomSizes[2502]={};
    scanf("%d%d",&N,&M);
    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
            scanf("%d",&map[i][j]);
        }
    }
    int numOfRoom = 0;
    int maxRoomSize = 0;
    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
            if(check[i][j] == 0){
                roomSizes[checkNum] = BFS(i,j);
                maxRoomSize = max(maxRoomSize,roomSizes[checkNum++]);
                numOfRoom++;
            }
        }
    }
    int maxRoomSize2 = 0;
    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
            if(i+1<M && check[i][j] != check[i+1][j]){
                int sum = roomSizes[check[i][j]] + roomSizes[check[i+1][j]];
                maxRoomSize2 = max(maxRoomSize2,sum);
            }
            if(j+1<N &&check[i][j] != check[i][j+1]){
                int sum = roomSizes[check[i][j]] + roomSizes[check[i][j+1]];
                maxRoomSize2 = max(maxRoomSize2,sum);
            }
        }
    }
    printf("%d\n",numOfRoom);
    printf("%d\n",maxRoomSize);
    printf("%d\n",maxRoomSize2);
}