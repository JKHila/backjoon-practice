#include <cstdio>
#include <cmath>
using namespace std;

class cicleQueue
{
  private:
    int q[51];
    int N;
    int LOR;

  public:
    cicleQueue(int N)
    {
        LOR = 0;
        this->N = N;
        for (int i = 0; i < N; i++)
        {
            this->q[i] = i+1;
        }
    }
    void left()
    {
        int H = q[0];
        for (int i = 1; i < N; i++)
        {
            q[i-1] = q[i];
        }
        q[N - 1] = H;
        LOR++;
    }
    void right()
    {
        int H = q[N - 1];
        for (int i = N - 2; i >= 0; i--)
        {
            q[i+1] = q[i];
        }
        q[0] = H;
        LOR++;
    }
    int pop()
    {
        int ret = q[0];
        for (int i = 1; i < N; i++)
        {
            q[i-1] = q[i];
        }
        this->N--;
        return ret;
    }
    int back(){
        return q[N-1];
    }
    int front(){
        return q[0];
    }
    int getIndex(int n){
        int res = 0;
        for(int i = 0;i<N;i++){
            if(q[i] == n){
                res = i;
                break;
            }
        }
        return res;
    }
    int getNum(){
        return N;
    }

    void showQueue()
    {
        for (int i = 0; i < N; i++)
        {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
    int getLOR(){
        return LOR;
    }
};

int main()
{
    int N = 0;
    int num = 0;
    int f[51];
    scanf("%d %d",&N,&num);
    for(int i = 0;i<num;i++){
        scanf("%d",&f[i]);
    }
    cicleQueue q(N);
    
    int cnt = 0;
    while(cnt != num){
        if(q.front() == f[cnt]){
            cnt++;
            q.pop();
        }else if(q.getIndex(f[cnt]) >= N/2){
            q.right();
        }else{
            q.left();
        }
    }
    printf("%d\n",q.getLOR());
}