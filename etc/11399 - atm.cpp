#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    vector<int> ve;
    scanf("%d",&N);

    ve.resize(N);
    int tp,res = 0;
    for(int i = 0;i<N;i++){
        scanf("%d",&ve[i]);
    }
    sort(ve.begin(),ve.end());

    int M = N;
    for(int i = 0;i<N;i++){
        res += ve[i]*M--;
    }
    printf("%d\n",res);
}