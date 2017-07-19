#include <cstdio>
#include <queue>
#include <list>
#include <functional>
using namespace std;
int map[26][26];
int check[26][26] ={};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int, int> > q;

int BFS(pair<int, int> n){
    int nx,ny;
    int ret = 1;    
    q.push(n);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        check[x][y] = 1;
        q.pop();
        for(int i = 0;i<4;i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(check[nx][ny] == -1 && map[nx][ny] == 1){
                q.push(make_pair(nx,ny));
                check[nx][ny] = 1;
                ret++;
            }
        }
    }
    return ret;
}

int main(){
    int N;
    char line[26];
    list<int> b;
    list<int>::iterator it;
    int res = 0;
    scanf("%d",&N);

    for(int i = 0;i<N;i++){
        scanf("%s",line);
        for(int j=0;j<N;j++){
            check[i][j] = -1;
            map[i][j] = line[j] - 48;
        }  
    }
    for(int i = 0;i<N;i++){
        for(int j=0;j<N;j++){
            if(check[i][j] == -1 && map[i][j] == 1){
                int tp = BFS(make_pair(i,j));
                b.push_back(tp);
                res++;
            }
        }
    }
    b.sort();
    printf("%d\n",res);
    for(it = b.begin();it != b.end();it++){
        printf("%d\n",*it);
    }

    /*for(int i = 0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d  ",check[i][j]);
        }
        printf("\n");
    }*/
    
}