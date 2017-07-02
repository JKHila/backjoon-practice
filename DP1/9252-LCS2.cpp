#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    char N1[1001];
    char N2[1001];
    char LCS[1001];
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

    stack <char> st;
    int index = 0;
    int i = len1;
    int j = len2;
    while (i > 0 && j > 0)
    {
        if (d[i][j] > d[i - 1][j - 1] && d[i][j] > d[i][j - 1] && d[i][j] > d[i - 1][j])
        {
            i = i - 1;
            j = j - 1;
            st.push(N1[i]);
        }
        else if (d[i][j] == d[i][j - 1])
        {
            j = j - 1;
        }else{
            i = i - 1;
        }
    }
    printf("%d\n", d[len1][len2]);
    while(!st.empty()){
        printf("%c",st.top());
        st.pop();
    }
    printf("\n");
}