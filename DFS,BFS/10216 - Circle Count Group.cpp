#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

float getDistance(pair<int, int> n, pair<int, int> m)
{
    return (n.first - m.first) * (n.first - m.first) + (n.second - m.second) * (n.second - m.second);
}

int countCircleGroup()
{
    queue<int> q;
    vector<pair<int, int> > vec;
    int r[3001];
    
    vector<int> link[3001];
    int check[3001]={};

    int N, x, y, res=0;

    scanf("%d", &N); //진영 좌표 입력
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d%d", &x, &y, &r[i]);
        vec.push_back(make_pair(x, y));
    }

    for (int i = 0; i < N; i++) //연결된 진영 있는지 확인해서 인접 리스트에 삽입
    {
        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                if ((r[i] + r[j])*(r[i] + r[j]) >= getDistance(vec[i], vec[j])) //두 지점 사이의 거리가 두 범위의 반지름 합보다 같거나 작을때 인접
                {
                    link[i].push_back(j);
                }
            }
        }
    }


    for(int i = 0;i<N;i++){ //BFS
        if(check[i] == 0){
            q.push(i);    
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                check[cur] = 1;
                for(int j = 0;j<link[cur].size();j++){
                    if(check[link[cur][j]] == 0){
                        check[link[cur][j]] = 1;
                        q.push(link[cur][j]);
                    }
                }
            }
            res++;
        }
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);

    int res = 0;

    while (T > 0)
    {
        res = countCircleGroup();
        printf("%d\n", res);
        T--;
    }
}