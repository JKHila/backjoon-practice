#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    char N[10];
    int M,tp = 0;
    int remote[11] = {0,1,2,3,4,5,6,7,8,9};
    
    
    scanf("%s",N);
    scanf("%d",&M);
    for(int i = 0;i<M;i++){ //입력받고 배열에 고장난 수에 -1대입
        scanf("%d",&tp);
        remote[tp] = -1;
    }

    int n = 0,cur = 0;
    for(int i = 0;i<strlen(N);i++){ //찾으려는 수 만들기
        cur = N[i] - 48;
        n += cur * pow(10,strlen(N)-(i+1));
    }

    int tmp = 0;
    for(int i = 0;i<10;i++){ //모든 버튼 고장나면 +,-만으로 답 도출
        //printf("dd%d\n",remote[i]);
        if(remote[i] == -1){
            tmp++;
        }
    }
    if(tmp == 10){
        printf("%d\n",100-n);
        return 0;
    }

    int btn=0,res=0;
    for(int i = 0;i<strlen(N);i++){ //숫자로 가까운 채널 버튼 누르기
        cur = N[i] - 48;
        if(remote[cur] != -1){
            btn += cur * pow(10,strlen(N)-(i+1));
            res++;
        } else{
            int j = 1;
            while(true){
                if(cur-j > 0 && remote[cur-j] != -1){
                    btn += cur-j * pow(10,strlen(N)-(i+1));
                    res++;
                    break;
                }else if(cur+j < 10 &&remote[cur+j] != -1){
                    btn += cur+j * pow(10,strlen(N)-(i+1));
                    res++;
                    break;
                }else{
                    j++;
                }
            }
        }
    }
    //printf("dd%d\n",btn);
    
    while(btn != n){ //가까운 채널에서 원하는 채널로 +,-
        if(btn > n){
            btn--;
            res++;
        }else if(btn < n){
            btn++;
            res++;
        }
    }
    if(fabs(100-n) < res) res = fabs(100-n);
    printf("%d\n",res);
}