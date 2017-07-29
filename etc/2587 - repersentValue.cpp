#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> a;
    a.resize(5);
    for(int i = 0;i<5;i++){
        scanf("%d",&a[i]);
    }

    sort(a.begin(),a.end());
    int ave = 0;
    for(int i = 0;i<5;i++){
        ave += a[i];
    }    
    printf("%d\n",ave/5);
    printf("%d\n",a[2]);
}