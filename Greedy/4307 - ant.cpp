#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);

    while(T > 0){
        int len,n;
        scanf("%d%d",&len,&n);
        int mx=0,mi=0,tp;
        for(int i = 0;i<n;i++){
            scanf("%d",&tp);
            mi = max(mi,min(tp,len-tp));
            mx = max(mx,max(tp,len-tp));
        }
        printf("%d %d\n",mi,mx);
        T--;
    }
}