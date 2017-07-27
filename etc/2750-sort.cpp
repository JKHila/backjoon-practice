#include <cstdio>
#include <list>
using namespace std;
int main(){
    int N = 0;
    list<int> li;
    scanf("%d",&N);

    int tp=0;
    for(int i = 0;i<N;i++){
        scanf("%d",&tp);
        li.push_back(tp);
    }
    li.sort();
    while(!li.empty()){
        printf("%d\n",li.front());
        li.remove(li.front());
    }
}