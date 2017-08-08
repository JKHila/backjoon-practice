#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;
queue<pair<int, int> > q;
int check[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int BFS(int M, int N,pair<int, int> n,vector<vector<int>> picture){
    int ret = 1;
    q.push(n);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        check[x][y] = 1;
        q.pop();
        for(int i = 0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx <M && ny >= 0 && ny <N){
                if(picture[nx][ny] > 0 && check[nx][ny] == 0 && picture[nx][ny] == picture[x][y]){
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = 1;
                    ret++;
                }
            }
        }
    }
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i = 0;i<m;++i){
        for(int j = 0;j<n;++j){
            check[i][j] = 0;
        }
    }
    for(int i = 0;i<m;++i){
        for(int j = 0;j<n;++j){
            if(picture[i][j] > 0 && check[i][j] == 0){
                max_size_of_one_area = max(max_size_of_one_area,BFS(m,n,make_pair(i,j),picture));
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}