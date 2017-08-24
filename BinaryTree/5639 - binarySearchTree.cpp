//1182
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef struct bTree{
    int data;
    struct bTree* left;
    struct bTree* right;
}bTree;

bTree *createNode(int data){
    bTree *newNode = (bTree*)malloc(sizeof(bTree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insert(int data, bTree* N){
    //printf("cnt:%d data:%d \n",cnt,N->data);
    if(data < N->data){
        if(N->left == NULL){
            bTree *newNode = createNode(data);
            N->left = newNode;
        }else{
            insert(data,N->left);
        }
    }else{
        if(N->right == NULL){
            bTree *newNode = createNode(data);            
            N->right = newNode;
        }else{
            insert(data,N->right);
        }
    }
}

void postOrder(bTree* node){
    if(node->left != NULL){
        postOrder(node->left);
    }
    if(node->right != NULL){
        postOrder(node->right);
    }    
    printf("%d\n",node->data);
}

int main(){
    int tp;
    bTree *root;
        
    int cnt = 0;
    while(scanf("%d",&tp) == 1){
        if(cnt++ == 0){
            root = createNode(tp);
        }else{
            insert(tp,root);
        }

        //if(tp == 60) break;
    }

    postOrder(root);
    /*for(int i = 0;i<N;i++){
        if(i == 0){
            root = createNode(tp);
        }else{
            insert(tp,root);
        }
        printf("%d\n",cnt);
    }*/
}