#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    vector<pair<int, int> > vec(N);
    for(int i = 0;i<N;i++){
        int f,s;
        scanf("%d%d",&f,&s);
        vec[i] = make_pair(s,f);
    }
    sort(vec.begin(),vec.end());
    int lastTime = 0,res = 0;
    for(int i = 0;i<N;i++){
        int sTime = vec[i].second;
        int eTime = vec[i].first;
        if(lastTime <= sTime){
            res++;
            lastTime = eTime;
        }
    }
    printf("%d\n",res);

}