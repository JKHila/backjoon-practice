#include <cstdio>
#include <string>
using namespace std;

int main(){
    char a[5][16];
    string res="";
    for(int i = 0;i<5;i++){
        for(int j = 0;j<16;j++){
            a[i][j] = '*';
        }
    }
    
    for(int i = 0;i<5;i++){
        scanf("%s",a[i]);
    }
    for(int i = 0;i<16;i++){
        for(int j = 0;j<5;j++){
            if(a[j][i] != '*' && a[j][i] != '\0')
                res += a[j][i];
        }
    }
    printf("%s\n",res.c_str());
}