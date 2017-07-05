#include <cstdio>
#include <list>
#include <cmath>
using namespace std;

int main(){
    char N[10];
    int M,tp = 0;
    list<int> li;
    list<int>::iterator it;// = ;
    
    for(int i = 0;i<10;i++){
        li.push_back(i);
    }
    scanf("%s",N);
    //printf("%lu",strlen(N));
    scanf("%d",&M);
    for(int i = 0;i<M;i++){
        scanf("%d",&tp);
        li.remove(tp);
    }
    
    /*for(it = li.begin();it != li.end();it++){
        printf("%d",*it);
    }*/

    int btn,res = 0;
    for(int i = 0;i<strlen(N);i++){
        for(it = li.begin();it != li.end();it++){
            //printf("dd%d %d\n",*it,N[i]-48);
            if(*it == N[i]-48){
                btn += (N[i]-48) * pow(10,strlen(N)-(i+1));
                res++;
                //printf("res%d\n",res);
                break;
            }
        }
        if((N[i]-48) - it++ > (N[i]-48) - it--){
            btn += *it * pow(10,strlen(N)-(i+1));
            res++;
        }
    }
    while(btn != N){
        if(btn > N){
            btn--;
            res++;
        }else if(btn < N{
            btn++;
            res++;
        }
    }
    printf("%d\n",res);
}