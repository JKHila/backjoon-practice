#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;
int main(){
    int N,tp;
    scanf("%d",&N);

    list<int> li;
    for(int i = 0;i<N;i++){
        scanf("%d",&tp);
        li.push_back(tp);
    }
    li.sort();

    int res = 0,cur = 0;
    list<int>::iterator it;
    for(it = li.begin();it != li.end();it++){
        cur += *it;
        res += cur;

    }
    printf("%d\n",res);
    

}