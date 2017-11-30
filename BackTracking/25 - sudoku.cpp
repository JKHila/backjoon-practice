#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int map[9][9];
vector<pair<int, int> > emptyList;
int flag = false;
void print_sudoku()
{
    flag = true;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
    return;
}
bool promising(int x,int y,int n){
    for(int i = 0;i<9;i++){
        if(y != i && map[x][i] == n)  return false;
        if(x != i && map[i][y] == n)  return false;
    }
    int startX = (x/3) * 3;
    int startY = (y/3) * 3;

    for(int i = startX;i < startX+3; i++){
        for(int j = startY;j < startY+3; j++){
            if(x != i && y != j)
                if(map[i][j] == n) return false;
        }    
    }
    return true;
}
void sudoku(int n){
    int x = emptyList[n].first;
    int y = emptyList[n].second;
    if(promising(x,y,map[x][y])){
        if(n == emptyList.size()) {
            if(!flag)
                print_sudoku();
        }
        else if(!flag){
            int nx = emptyList[n+1].first;
            int ny = emptyList[n+1].second;
            for (int j = 1; j <= 9; j++)
            {
                map[nx][ny] = j;
                sudoku(n+1);
                map[nx][ny] = 0;
            }
        }
    }
}
int main(){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            scanf("%1d",&map[i][j]);
            if(map[i][j] == 0){
                emptyList.push_back(make_pair(i,j));
            }
        }
    }
    int x = emptyList[0].first;
    int y = emptyList[0].second;
    for(int i = 1;i<=9;i++){
        map[x][y] = i;
        sudoku(0);
    }
}