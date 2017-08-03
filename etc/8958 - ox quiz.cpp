#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int T,cur = 0,total = 0;
    char st[90];
    scanf("%d",&T);

    while(T > 0){
        scanf("%s",st);
        total = 0, cur = 0;
        for(int i = 0;i<strlen(st);i++){
            if(st[i] == 'O'){
                cur++;
            }else{
                cur = 0;
            }
            total += cur;
        }
        printf("%d\n",total);
        T--;
    }

    
}