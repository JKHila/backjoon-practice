#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int main(){
    int N,tp;
    long long cnt=0;
    scanf("%d",&N);

    vector<int> vec(N+2,0);
    vec[0] = vec[N+1] = -1;

    set<int> se;
    se.insert(0);   se.insert(N+1);
    for(int i = 0;i<N;i++){
        scanf("%d",&tp);
        se.insert(tp);
        set<int>::iterator itL = se.find(tp);
        set<int>::iterator itR = se.find(tp);
        itL--;itR++;

        //printf("ss%d %d\n",*itL,*itR);
        vec[tp] = max(vec[*itL],vec[*itR]) + 1;
        cnt += vec[tp];
        printf("%lld\n",cnt);
    }
}