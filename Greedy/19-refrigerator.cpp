#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N,a,b;
    vector<pair<int, int> > arr;
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%d %d",&a,&b);
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(),arr.end());
    for(int i = 0;i<N;i++){
        printf("%d %d %d\n",i,arr[i].first,arr[i].second);
    }
    int res = 1;
    int refNum = 0;
    for(int i = 1;i<N;i++){
        bool flag = false;
        for(int j = refNum;j<i;j++){
            if(arr[i].first > arr[j].second){
                flag = true;
                refNum = i;
                break;
            }
        }
        if(flag)
            res++;
    }
    printf("%d\n",res);
     
}