#include <cstdio>
#include <set>
using namespace std;
int main(){
    int N,M,tp;
    set<int> se;
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%d",&tp);
        se.insert(tp);
    }
    scanf("%d",&M);
    for(int i = 0;i<M;i++){
        scanf("%d",&tp);
        set<int>::iterator it = se.find(tp);
        if(it != se.end()) printf("%d\n",1);
        else printf("%d\n",0);
    }
}