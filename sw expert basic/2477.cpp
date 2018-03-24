#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M,K,A,B;
int a[10];
int b[10];
int r[1001];
bool isSecond[1001];
int usingN[10][2];
int usingM[10][2];
int usedK[1001][2];

queue<int> nQ;
queue<int> mQ;
int getEmptyN(){
    int ret = -1;
    for(int i = 1;i<=N;i++){
        if(usingN[i][0] == 0){
            ret = i;
            break;
        }
    }   
    return ret;
}
int getEmptyM(){
    int ret = -1;
    for(int i = 1;i<=M;i++){
        if(usingM[i][0] == 0){
            ret = i;
            break;
        }
    }   
    return ret;
}
void dealWork(){
    for(int i = 1;i<=N;i++){
        if(usingN[i][0] > 0){
            usingN[i][0]--;
            if(usingN[i][0] == 0){
                mQ.push(usingN[i][1]);
                //cout<<"N done"<<i<<" "<<usingN[i][1]<<endl;
            }
        }
        //cout<<"remain"<<i<<" "<<usingN[i][0] <<endl;        
    }
    for(int i = 1;i<=N;i++){
        if(usingM[i][0] > 0){
            usingM[i][0]--;
        }
    }   
}
int findAns(){
    int ans = -1;
    bool flag = false;
    for(int i = 1;i<= K;i++){
        //cout <<i << " "<< usedK[i][0] << " "<< usedK[i][1] <<endl;
        if(usedK[i][0] == A && usedK[i][1] == B){
            flag = true;
            ans += i;
        }
    }
    if(flag) ans++;
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t = 1; t <= T; t++){
        scanf("%d %d %d %d %d",&N,&M,&K,&A,&B);
        for(int i = 1;i <= N;i++){
            scanf("%d",&a[i]);
        }
        for(int i = 1;i <= M;i++){
            scanf("%d",&b[i]);
        }
        for(int i = 1;i <= K;i++){
            scanf("%d",&r[i]);
        }

        int cur = 0;     
        memset(usedK, -1 , sizeof(usedK));
        memset(isSecond, 0 , sizeof(isSecond));
        for(int cur = 0; cur <= r[K-1]+K+1000; cur++){
           // cout<<"cur time : "<<cur<<endl;            
            for(int i = 1;i<=K;i++){
                if(cur == r[i]){
                    nQ.push(i);
                    //cout<<"user arrive: "<<i<<endl;
                }            
            }
            int eN = getEmptyN();          
            while(eN > 0 && !nQ.empty()){
                int first = nQ.front();  
                usingN[eN][0] = a[eN];  //창구일처리 카운트
                usingN[eN][1] = first;  //현재 창구 사용 사람 번호
                usedK[first][0] = eN;   //사람의 창구 사용 번호 저장
                nQ.pop();
                //cout<<"user use N: "<<first<<" "<<eN<<endl;
                eN = getEmptyN();                          
            }
            int eM = getEmptyM();         
            while(eM > 0 && !mQ.empty()){
                int second = mQ.front();
                usingM[eM][0] = b[eM];  //창구일처리 카운트
                usingM[eM][1] = second;  //현재 창구 사용 사람 번호
                usedK[second][1] = eM;   //사람의 창구 사용 번호 저장
                mQ.pop();       
                //cout<<"user use M: "<<second<<" "<<eM<<endl;     
                eM = getEmptyM();         
            }
            dealWork();
            /* cout<<usingN[1][1]<<" "<<usingN[2][1]<<" "<<usingM[1][1]<<" "<<usingM[2][1]<<endl;
            cout<<usingN[1][0]<<" "<<usingN[2][0]<<" "<<usingM[1][0]<<" "<<usingM[2][0]<<endl;            
            cout<<endl; */
        }
        printf("#%d %d\n",t,findAns());

        memset(usingM, 0 , sizeof(usingM));
        memset(usingN, 0 , sizeof(usingN));   
    }
}