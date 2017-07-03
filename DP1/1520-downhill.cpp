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
        return 1;
    }
    if(d[row][col] >= 0){
        return d[row][col];
    }

    if (d[row][col] == -1)
        d[row][col] = 0;
    
    for (int i = 0; i < 4; i++)
    {
        if(row + dx[i] >= 0 && row + dx[i] <= maxRow && col + dy[i]>=0 && col + dy[i] <= maxCol)
            if (t[row + dx[i]][col + dy[i]] < t[row][col])
                d[row][col] += downHill(row + dx[i], col + dy[i], maxRow, maxCol);
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

    /*for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d   ",d[i][j]);
        }
        printf("\n");
    }*/

    printf("%d\n", d[0][0]);
}