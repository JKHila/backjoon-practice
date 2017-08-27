#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int N;
int res = 0;
bool check(vector<int> vec, int newRow){
    int curRow = 0;
    while(curRow < newRow){
        if(vec[newRow] == vec[curRow] || fabs(vec[newRow]-vec[curRow])==(newRow-curRow)){
            return true;
        }
        ++curRow;
    }
    return false;
}
void f(vector<int> vec,int row){
    if(!check(vec,row)){
        if(row == N-1){                
            res++;
        }else{
            for(int i = 0;i<N;++i){
                vec[row+1] = i;
                f(vec,row+1);
            }
        }
    }
}
int main(){
    scanf("%d",&N);

    vector<int> vec(N,0);
    for(int i = 0;i<N;++i){
        vec[0] = i;
        f(vec,0);
    }
    printf("%d\n",res);
}