#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    char N1[1001];
    char N2[1001];
    int d[1002][1002]={};
    scanf("%s",N1);
    scanf("%s",N2);

    int len1 = strlen(N1);
    int len2 = strlen(N2);
    for(int i = 0;i<=len1;i++){
        d[i][0] = 0;
    }
    for(int i = 0;i<=len2;i++){
        d[0][i] = 0;
    }

    for(int i = 1;i<=len1;i++){
        for(int j = 1;j<=len2;j++){

            if(N1[i-1] == N2[j-1]){
                d[i][j] = d[i-1][j-1]+1;
            }else{
                d[i][j] = max(d[i-1][j],d[i][j-1]);
            }
        }
    }

    printf("%d\n",d[len1][len2]);

}