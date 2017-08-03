#include <cstdio>
using namespace std;
int main(){
    int a[10];
    int b[10];

    int aScore=0,bScore=0;
    for(int i = 0;i<10;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<10;i++){
        scanf("%d",&b[i]);
    }
    for(int i = 0;i<10;i++){
        if(a[i] > b[i]){
            aScore++;
        }else if(a[i] < b[i]){
            bScore++;
        }
    }

    if(aScore > bScore){
        printf("A");
    }else if(aScore < bScore){
        printf("B");        
    }else{
        printf("D");        
    }

}