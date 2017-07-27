#include <cstdio>
#include <list>
#include <functional>

using namespace std;

int main(){
    int tp,N = 0;
    list<int> A;
    list<int> B;
    list<int>::iterator itA;
    list<int>::iterator itB;
    scanf("%d",&N);
    for(int j = 0;j<N;j++){
        scanf("%d",&tp);
        A.push_back(tp);
    }
    for(int j = 0;j<N;j++){
        scanf("%d",&tp);
        B.push_back(tp);
    }

    A.sort(greater<int>());
    B.sort();
    
    int res = 0;
    for(itB = B.begin(),itA = A.begin();itA != A.end();itA++,itB++){
        res += *itB * *itA;
        //printf("%d",*it);
    }
    printf("%d\n",res);
    
}