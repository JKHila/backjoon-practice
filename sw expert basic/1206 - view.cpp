#include <cstdio>
#include <algorithm>
using namespace std;
int count(){
    int n,res = 0;
    int row[1001];
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",row + i);
        //printf("%d ", row[i]);
    }
    for(int i = 2; i <= n-2;i++){
        if(row[i-2] < row[i] && row[i-1] < row[i] && row[i+1] < row[i] && row[i+2] < row[i]){
            int tp = max(row[i-2],max(row[i-1],max(row[i+1],row[i+2])));
            res += row[i] - tp;
        }
    }
    return res;
}
    
int main(){
    for(int t = 1; t <= 10; t++){
        int res = count();
        printf("#%d %d\n",t,res);
    }
}