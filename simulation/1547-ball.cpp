#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int N = 0;
    int x,y = 0;
    int ball[3] ={1,0,0};
    int tmp,res = 1;
    scanf("%d",&N);

    for(int i = 0;i<N;i++){
        scanf("%d %d",&x, &y);

        tmp = ball[x-1];
        ball[x-1] = ball[y-1];
        ball[y-1] = tmp;

        if(ball[x-1] == 1){
            res = x;
        }else if(ball[y-1] == 1){
            res = y;
        }
    }

    printf("%d\n",res);
    

    
}