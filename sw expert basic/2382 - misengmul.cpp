#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M, K;
typedef struct node
{
    int x;
    int y;
    int n;
    int d;
} node;
//vector<pair<pair<int,int>, pair<int,int> > > vec;
vector<node> vec;
void printStat()
{
    for (int i = 0; i < vec.size(); i++)
    {
        //printf("%d %d %d %d %d\n",i,vec[i].first.first,vec[i].first.second,vec[i].second.first,vec[i].second.second);
    }
    cout << endl;
}
void printVec()
{
    int map[100][100] = {};
    for (int j = 0; j < vec.size(); j++)
    {
        map[vec[j].x][vec[j].y] = vec[j].n;
        //printf("%d %d %d %d\n",,..second.second);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d   ", map[i][j]);
        }
        cout << endl;
    }
    cout << vec.size() << endl;
}
int step()
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue<int> q[100][100];
    
    for (int i = 0; i < M; i++)
    {

        for (int j = 0; j < vec.size(); j++)
        { //move
            if (vec[j].n == 0)
                continue;
            int dir = vec[j].d;
            vec[j].x += dx[dir - 1];
            vec[j].y += dy[dir - 1];
            q[vec[j].x][vec[j].y].push(j);
        }

        for (int j = 0; j < vec.size(); j++)
        { //change dir
            if (vec[j].n == 0)
                continue;

            int x = vec[j].x;
            int y = vec[j].y;
            if (x == 0 || y == 0 || x == N - 1 || y == N - 1)
            {
                vec[j].n /= 2;
                switch (vec[j].d)
                {
                case 1:
                    vec[j].d = 2;
                    break;
                case 2:
                    vec[j].d = 1;
                    break;
                case 3:
                    vec[j].d = 4;
                    break;
                case 4:
                    vec[j].d = 3;
                    break;
                }
            }
            else if (q[vec[j].x][vec[j].y].size() > 1)
            {
                int mxN = 0, mx = 0, ms = 0, mxD;
                while (!q[vec[j].x][vec[j].y].empty())
                {
                    int tpN = q[vec[j].x][vec[j].y].front();
                    ms += vec[tpN].n;
                    if (mx < vec[tpN].n)
                    {
                        mxN = tpN;
                        mxD = vec[tpN].d;
                        mx = vec[tpN].n;
                    }
                    vec[tpN].n = 0;
                    q[vec[j].x][vec[j].y].pop();
                }
                vec[mxN].n = ms;
                vec[mxN].d = mxD;
            }
            else if (q[vec[j].x][vec[j].y].size() > 0)
            {
                q[vec[j].x][vec[j].y].pop();
            }
        }
        //printVec();
    }
    int ret = 0;
    for (int j = 0; j < vec.size(); j++)
    {
        if (vec[j].n > 0)
        {
            ret += vec[j].n;
        }
    }
    return ret;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d%d%d", &N, &M, &K);
        for (int i = 0; i < K; i++)
        {
            int x, y, n, d;
            node nd;
            scanf("%d%d%d%d", &x, &y, &n, &d);
            nd.x = x;
            nd.y = y;
            nd.n = n;
            nd.d = d;
            vec.push_back(nd);
        }
        printf("#%d %d\n", t, step());
        vec.clear();
    }
}