#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a;


int binarySearch(int size,int target){
    int l = 0;
    int r = size -1;

    while(l <= r){
        int mid = (l + r) / 2;
        if(target == a[mid]){
            return 1;
        }else if(target > a[mid]){
            l = mid +1;
        }else{
            r = mid -1;
        }
    }

    return 0;
}

int main(){
    int N,M;

    scanf("%d",&N);
    a.reserve(N+1);
    for(int i = 0;i<N;i++){
        scanf("%d",&a[i]);
    }
    sort(a.begin(),a.begin()+N);

    scanf("%d",&M);

    int target;
    for(int i = 0;i<M;i++){
        scanf("%d",&target);
        printf("%d\n",binarySearch(M,target));
    }
}