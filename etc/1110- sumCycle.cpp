#include <cstdio>
using namespace std;

int main(){
    int N = 0;
    scanf("%d",&N);

    int a = N / 10,b = N % 10;
    int next = a + b;
    int cnt = 1;
    int newNum = 0;

    while(true){
        a = b;
        b = next % 10;
        next = a + b;
        newNum = a*10 + b;
        if(newNum == N)
            break;
        cnt++;
    }
    printf("%d\n",cnt);
}