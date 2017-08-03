#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int N = 0;
    int arr[1000000];
    char res[1000000];
    stack <int> st;
    scanf("%d",&N);

    for(int i = 0;i<N;i++){
        scanf("%d",&arr[i]);
    }

    int cur = 0;
    int num = 1;

    for(int i =0;i<N*2;i++){
        if(!st.empty() && st.top() == arr[cur]){
            st.pop();
            cur++;
            res[i] = '-';
        }else{
            st.push(num++);
            res[i] = '+';
        }
    }
    if(st.empty()){
        for(int i  = 0;i<N*2;i++){
            printf("%c\n",res[i]);
        }
    }else{
        printf("NO");
    }
}