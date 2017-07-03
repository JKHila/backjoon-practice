#include <cstdio>
using namespace std;

int t[501][501];
int d[501][501];
int res;
int downHill(int row, int col, int maxRow, int maxCol)
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    if (row == maxRow && col == maxCol)
    {
        return 1; //끝에 도달하면 1리턴
    }
    if(d[row][col] >= 0){
        return d[row][col]; //이미 계산한값이면 d테이블값 리턴
    }

    if (d[row][col] == -1)
        d[row][col] = 0; //처음 검사할 때 0 대입
    
    for (int i = 0; i < 4; i++)
    {
        if(row + dx[i] >= 0 && row + dx[i] <= maxRow && col + dy[i]>=0 && col + dy[i] <= maxCol)
            if (t[row + dx[i]][col + dy[i]] < t[row][col])
                d[row][col] += downHill(row + dx[i], col + dy[i], maxRow, maxCol); //재귀로 움직이며 d값 더함
    }
    return d[row][col];
}

int main()
{
    int row, col = 0;

    scanf("%d %d", &row, &col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            d[i][j] = -1;
            scanf("%d", &t[i][j]);
        }
    }
    downHill(0,0,row-1,col-1);

    printf("%d\n", d[0][0]);
}