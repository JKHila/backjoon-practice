#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char st[20];
    int sec[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
    scanf("%s", st);

    int num = 0;
    int res = 0;
    for (int i = 0; i < strlen(st); i++){
        res += sec[st[i] - 65];
    }
    printf("%d\n",res);
}