#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int T;
    int n;
    char ch[30];
    scanf("%d",&T);

    while(T > 0){
         scanf("%d %s",&n,ch);
         for(int i = 0;i<strlen(ch);i++){
             for(int j = 0;j<n;j++){
                 printf("%c",ch[i]);
             }
         }
         printf("\n");
         T--;
    }
}