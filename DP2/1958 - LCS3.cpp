#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    char N1[101];
    char N2[101];
    char N3[101];
    int d[102][102][102]={};
    scanf("%s",N1);
    scanf("%s",N2);
    scanf("%s",N3);

    int len1 = strlen(N1);
    int len2 = strlen(N2);
    int len3 = strlen(N3);
    for(int i = 0;i<=len1;i++){
        d[i][0][0] = 0;
    }
    for(int i = 0;i<=len2;i++){
        d[0][i][0] = 0;
    }
    for(int i = 0;i<=len3;i++){
        d[0][0][i] = 0;
    }

    for(int i = 1;i<=len1;i++){
        for(int j = 1;j<=len2;j++){
            for(int k = 1;k<=len3;k++){
                if(N1[i-1] == N2[j-1] && N2[j-1] == N3[k-1]){
                    d[i][j][k] = d[i-1][j-1][k-1]+1;
                }else{
                    d[i][j][k] = max(d[i-1][j][k],max(d[i][j-1][k],d[i][j][k-1]));
                }
            }
        }
    }

    printf("%d\n",d[len1][len2][len3]);

}