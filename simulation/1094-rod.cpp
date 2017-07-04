#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int N,min = 0;
    int fRod = 64;
    stack<int> rods;
    scanf("%d",&N);

    rods.push(fRod);
    while(fRod > N){
        min = rods.top();
        rods.pop();
        rods.push(min/2);
        rods.push(min/2);
        if(fRod-rods.top() >= N){
            fRod -= rods.top();
            rods.pop();
        }
    }

    printf("%lu\n",rods.size());
}