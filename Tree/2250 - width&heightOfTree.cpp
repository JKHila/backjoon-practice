#include <cstdio>
#include <vector>
using namespace std;

int tree[10001][2];
vector<int> vec[10001];
bool isChild[10001];

int col = 0;

void inOrder(int n,int level){
    if(tree[n][0] > 0){
        inOrder(tree[n][0],level+1);
    }
    vec[level].push_back(col++);
    if(tree[n][1] > 0){
        inOrder(tree[n][1],level+1);
    }
}

int main(){
    int N;
    scanf("%d",&N);
    int tp,l,r;

    for(int i = 0;i<N;i++){
        scanf("%d%d%d",&tp,&l,&r);
        tree[tp][0] = l;
        tree[tp][1] = r;

        if(l != -1) isChild[l] = true;
        if(r != -1) isChild[r] = true;
    }

    int root = 0;
    for(int i = 1;i<=N;i++){
        if(!isChild[i]){
            root = i;
        }
    }

    inOrder(root,1);

    int res = 0,maxCol = 0;
    for(int i = 1;vec[i].size();i++){
        int cur = vec[i].back() - vec[i].front() + 1;
        if(res < cur){
            res = cur;
            maxCol = i;
        }
    }
    printf("%d %d\n",maxCol,res);
}