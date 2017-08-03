#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int len = 0;
    char N[101];
    int res = 0;
    scanf("%d",&len);
    scanf("%s",N);

    for(int i = 0;i<len;i++){
        res += (int)N[i] - 48;
    }

    printf("%d\n",res);
}