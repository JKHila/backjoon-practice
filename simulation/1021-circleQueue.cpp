#include <cstdio>
#include <deque>
#include <queue>
using namespace std;

deque<int> dq;
int getIndex(int n)
{
    int ret = 0;
    for (int i = 0; i < dq.size(); i++)
    {
        if (dq[i] == n)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

int main()
{
    int N, M = 0;
    queue<int> Q;
    scanf("%d %d", &N, &M);

    for(int i = 0;i<N;i++){
        dq.push_back(i+1);
    }
    int temp = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &temp);
        Q.push(temp);
    }

    int res= 0;
    while (!Q.empty())
    {
        if (dq.front() == Q.front())
        {
            dq.pop_front();
            Q.pop();
        }
        else if (getIndex(Q.front()) > dq.size() / 2)
        {
            dq.push_front(dq.back());
            dq.pop_back();
            res++;
        }
        else
        {
            dq.push_back(dq.front());
            dq.pop_front();
            res++;
        }
    }
    printf("%d\n", res);
}