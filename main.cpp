#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int T=0,N=0,L=0,K=0;
    long long rod[5000000] = {};
    int realId[100001];
    int idPos[100001];
    int direction[100001];
    int fallAnts[100001];

    scanf("%d",&T);

    
    while(T > 0){
        int pos = 0,id = 0,absId = 0,fallAnt = 0,nextAntId = 0,preAntId = 0;
        scanf("%d %d %d",&N,&L,&K); //개미수,막대길이,K번째로 떨어지는 개미 찾아야함.

        for(int i = 0;i<N;i++){ //초기위치, 아이디값 입력
            scanf("%d %d",&pos,&id);
            rod[pos] = id;
            absId = fabs(id);
            realId[absId] = id;
            idPos[absId] = pos;
            if(id > 0)  direction[absId] = 1;
            else    direction[absId] = -1;
        }

        while(true){
            /*for(int i = 1;i <= N;i++){ //방향 변경
                nextAntId = fabs(rod[idPos[i]+direction[i]]);
                if(nextAntId != 0 && direction[nextAntId]*direction[i] == -1){
                    direction[nextAntId] *= -1;
                    direction[i] *= -1;
                }
            }*/ //이동
            for(int i = 1;i <= N;i++){
                if(idPos[i] > 0 && idPos[i] < L){
                    if(rod[idPos[i]] == realId[i])  rod[idPos[i]] = 0;
                    idPos[i] += direction[i];
                    preAntId = fabs(rod[idPos[i]]);
                    if(rod[idPos[i]] != 0 &&  preAntId < fabs(realId[i])){
                        direction[i] *= -1;
                        direction[preAntId] *= -1;
                    }
                    rod[idPos[i]] = realId[i];
                }else{
                    if(realId[i] != 0){
                        fallAnt++;
                        fallAnts[fallAnt] = realId[i];
                        realId[i] = 0;
                        rod[idPos[i]] = 0;
                    }
                }
            }
            /*for(int i = 0;i < L;i++){
                printf("%lld ",rod[i]);
            }
            printf("\n");
            for(int i = 1;i <= N;i++){
                printf("%d ",direction[i]);
            }
            printf("\n");*/
            if(fallAnt >= K){
                /*for(int i = 0;i<N;i++){
                    printf("fall%d\n",fallAnts[i]);
                    
                }*/
                printf("%d\n",fallAnts[K]);
                break;
            }
        }
        T--;
    }
}