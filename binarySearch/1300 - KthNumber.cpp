#include <cstdio>
#include <algorithm>

using namespace std;
int main(){
    int k,N;
    scanf("%d%d",&N,&k);

    int l = 1, r = k, m,res;
    while(l <= r){
        m = (l + r) / 2;
        int cnt = 0;
        for(int i = 1;i<=N;i++){
            cnt += min(m / i, N);
        }
        if(cnt < k){
            l = m +1;
        }else{
            res = m;
            r = m -1;
        }
    }
    printf("%d\n",res);
}