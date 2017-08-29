#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N,tp;
    scanf("%d",&N);
    vector<int> vc(N,0);
    
    for(int i = 0;i<N;i++){
        scanf("%d",&vc[i]);
    }
    sort(vc.begin(),vc.end());
    int res = 0;
    for(int i = N-1;i>=0;i--){
        res = max(res, vc[i]*(N-i));
    }
    printf("%d\n",res);
}