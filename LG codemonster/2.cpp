#include<cstdio>
#include<algorithm>
using namespace std;
int getBab(char b){
    if(b == 'B'){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    FILE *out;
    out = fopen("output.txt","w");
    int N,T;
    char tp;


    scanf("%d",&T);
    while(T>0){
        char map[501][501] = {0};
        int upd[501][501] = {0};
        int downd[501][501] = {0};
        int ans = 0;
        scanf("%d",&N);
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                scanf("%c%c",&tp,&map[i][j]);
            }
        }
        upd[N-1][0] = getBab(map[N-1][0]);
        for(int i = N-2;i>=0;i--){
            upd[i][0] = upd[i+1][0] + getBab(map[i][0]);
        }
        for(int i = 1;i<N;i++){
            upd[N-1][i] = upd[N-1][i-1] + getBab(map[N-1][i]);
        }
        for(int i = N-2;i>=0;i--){
            for(int j = 1;j<N;j++){
                upd[i][j] = max(upd[i][j-1],upd[i+1][j]) + getBab(map[i][j]);
            }
        }

        downd[N-1][N-1] = getBab(map[N-1][N-1]);
        for(int i = N-2;i>=0;i--){
            downd[i][N-1] = downd[i+1][N-1] + getBab(map[i][N-1]);
        }
        for(int i = N-2;i>=0;i--){
            downd[N-1][i] = downd[N-1][i+1] + getBab(map[N-1][i]);
        }
        for(int i = N-2;i>=0;i--){
            for(int j = N-2;j>=0;j--){
                downd[i][j] = max(downd[i][j+1],downd[i+1][j]) + getBab(map[i][j]);
            }
        }

        for(int i = 0;i<N;i++){
            for(int j = 0;j<N-1;j++){
                //printf("[%d %d] ",upd[i][j], downd[i][j]);
                ans = max(ans,upd[i][j]+downd[i][j+1]);
            }
            //printf("\n");
        }
        fprintf(out,"%d\n",ans);

        T--;
    }
}