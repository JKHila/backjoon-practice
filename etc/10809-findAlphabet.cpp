#include <cstdio>
#include <cstring>
using namespace std;
 
int main(){
    char st[105];
    int alpha[27];
    scanf("%s",st);
    
    for(int i = 0;i<26;i++){
        alpha[i] = -1;
    }

    for(int i = 0;i<strlen(st);i++){
        if(alpha[st[i]-97] == -1)
            alpha[st[i]-97] = i;
    }
    for(int i = 0;i<26;i++){
        printf("%d ",alpha[i]);
    }
    printf("\n");

}