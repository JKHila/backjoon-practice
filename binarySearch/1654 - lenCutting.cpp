#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int k,N;
    scanf("%d%d",&k,&N);

    vector<long long> a(k);
    
    long long l = 0, r = pow(2,31)-1, m =0;    
    for(int i = 0;i<k;i++){
        scanf("%lld",&a[i]);
        //r = max(r,a[i]);
    }

    int res = 0;
    while(l <= r){
        m = (l + r) / 2;
        int cnt = 0;
        for(int i = 0;i<k;i++){
            cnt += a[i] / m;
        }
        if(cnt >= N){
            res = max(res,(int)m);
            l = m + 1;
        }else{
            r = m - 1;            
        }
    }
    printf("%d\n",res);
}