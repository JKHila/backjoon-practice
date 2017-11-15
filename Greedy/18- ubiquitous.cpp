#include <cstdio>
using namespace std;
typedef struct node
{
    node *parent;
    int key;
} node;
node* find_set(node *n)
{
    while (n->parent != n)
    {
        n = n->parent;
    }
    return n;
}
int main()
{
    int N, M, a, b;
    node *arr[50001] = {};
    scanf("%d %d", &N, &M);
    for(int i = 1;i<=N;i++){
        arr[i] = new node;
        arr[i] ->parent = arr[i];
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &a, &b);
        find_set(arr[b]) -> parent = find_set(arr[a]);
    }
    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        if (arr[i]->parent == arr[i]){
            res++;
            //printf("%d\n",i);
        }
    }
    printf("%d\n", res);
}