#include <cstdio>
using namespace std;
#define MAX 68000000

int N;

char t[MAX];

void preOrder(int n){
    printf("%c",t[n]);
    if(t[2*n+1] != '.')
        preOrder(2*n+1);
    if(t[2*n+2] != '.')
        preOrder(2*n+2);
}

void inOrder(int n){
    if(t[2*n+1] != '.')
        inOrder(2*n+1);
    printf("%c",t[n]);    
    if(t[2*n+2] != '.')
        inOrder(2*n+2);
}

void postOrder(int n){
    if(t[2*n+1] != '.')
        postOrder(2*n+1);
    if(t[2*n+2] != '.')
        postOrder(2*n+2);
    printf("%c",t[n]);            
}

int getIndex(char ch){
    int ret = -1;
    for(int i = 0;i<MAX;i++){
        if(t[i] == ch){
            ret = i;
            break;
        }
    }
    return ret;
}
int main(){
    
    scanf("%d",&N);
    char tp[100];
    for(int i = 0;i<MAX;i++){
        t[i] = '.';
    }
    t[0] = 'A';
    for(int i = 0;i<N;i++){
        scanf("%s",tp);
        int idx = getIndex(tp[0]);
        scanf("%s",tp);        
        t[2*idx+1] = tp[0];
        scanf("%s",tp);        
        t[2*idx+2] = tp[0];
    }
    /*for(int i = 0;i<100;i++){
       printf("%c ",t[i]);
    }
    printf("\n");*/
    
    preOrder(0);
    printf("\n");
    inOrder(0);
    printf("\n");
    postOrder(0);
    printf("\n");
    
}