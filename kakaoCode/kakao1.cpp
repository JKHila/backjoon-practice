#include <cstdio>
using namespace std;
int map[17][17];
void setBinary(int line,int size,int n){
    while(n >= 0){
        if(n % 2 == 0 && map[line][size] == 0){
            map[line][size--] = 0;
        }else{
            map[line][size--] = 1;
        }
        n /= 2;
        if(n == 0)  break;        
        
    }
}
int main(){
    int N;
    int arr1[17];
    int arr2[17];
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%d",&arr1[i]);
        setBinary(i,N-1,arr1[i]);
    }
    for(int i = 0;i<N;i++){
        scanf("%d",&arr2[i]);
        setBinary(i,N-1,arr2[i]);        
    }

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(map[i][j] == 1){
                printf("#");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}