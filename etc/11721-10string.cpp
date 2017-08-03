#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    char str[105];
    scanf("%s",str);
    //str += '\0';

    for(int i = 0;i<=strlen(str)/10;i++){
        for(int j = i*10;j<10*(i+1);j++){
            if(str[j] == '\0') break;
            printf("%c",str[j]);
        }
        printf("\n");
    }
}