#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int N;
int getSum(int n){
    int nl = 2*n,nr = nl+1;

    if(nl > N|| nr > N) return vec[n];
    
    int l = getSum(nl);
    int r = getSum(nr);

    if(l > r){
        vec[nr] += l-r;
    }else if(r > l){
        vec[nl] += r-l;
    }
    return vec[n] + max(l,r);
}

int main(){
    int k;
    scanf("%d",&k);
    N = pow(2,k+1)+1;
    vec.reserve(N);

    for(int i = 2;i<pow(2,k+1);i++){
        scanf("%d",&vec[i]);
    }
    getSum(1);
    
    int res=0;
    for(int i = 2;i<N-1;i++){
        printf("%d\n",vec[i]);
        res += vec[i];
    }
    printf("%d\n",res);
}