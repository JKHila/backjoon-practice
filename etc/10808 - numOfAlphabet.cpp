#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    char st[101];
    int a[27] ={};
    scanf("%s",st);
    
    int tp = 0;
    for(int i = 0;i<strlen(st);i++){
        tp = (int)st[i] - 97;
        //printf("%d ",tp);
        a[tp]++;
    }

    for(int i = 0;i<26;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}