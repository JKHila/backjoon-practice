#include <cstdio>
using namespace std;
#define MAX 10000
int getSumOfPlaceValue(int n){
    int res = 0;
    while(n != 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main(){
    bool a[MAX+1] ={};
    for(int i = 1;i<=MAX;i++){
        if(i+getSumOfPlaceValue(i) <= MAX){
            a[i+getSumOfPlaceValue(i)] = true;
            
        }
    }
    for(int i = 1;i<=MAX;i++){
        if(!a[i]){
            printf("%d\n",i);
        }
    }
}