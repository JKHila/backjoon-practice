#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct customer{
    int num;
    int aNum;  //창구1에서 이용한 창구번호
    int bNum;  //창구2에서 이용한 창구번호
    int t;  //도착시간
    int state;  //0:도착x, 1:창구 1, 2: 창구 2 3:집감
};
struct changu{
    int t;  //처리하는데 걸리는 시간
    int deal; //처리해야되는 시간
    int cusNum; //처리하는 사람
};
int N,M,K,A,B;
changu a[10];
changu b[10];

vector<customer> vec;
int solve(){
    queue<int> aQ;
    queue<int> bQ;
    int cur = 0;
    int cnt = 0;
    int ans = 0;
    
    while(cnt < K){
        for (int i = 0; i < M; i++){
            //대기 인원 있고 빈 창구 있을때 창구에 일할당            
            if(!bQ.empty() && !b[i].deal){
                b[i].cusNum = bQ.front();
                vec[b[i].cusNum].bNum = i+1; //창구번호 저장
                b[i].deal = b[i].t;
                bQ.pop();
            }
            //일 처리
            if(b[i].deal > 0){
                b[i].deal--;
                //일 끝났으면 창구2보냄
                if(b[i].deal == 0){
                    cnt++;
                }            
            }
        }
        
        for(int i = 0;i<K;i++){
            //도착하면 창구1로 보냄
            if(vec[i].t == cur){
                aQ.push(i);
            }
        }
        
        for (int i = 0; i < N; i++)
        {
            //대기 인원 있고 빈 창구 있을때 창구에 일할당
            if (!aQ.empty() && !a[i].deal)
            {
                a[i].cusNum = aQ.front();
                vec[a[i].cusNum].aNum = i+1; //창구번호 저장
                a[i].deal = a[i].t;
                aQ.pop();
            }
            //일 처리
            if(a[i].deal > 0){
                a[i].deal--;
                //일 끝났으면 창구2보냄
                if(a[i].deal == 0){
                    bQ.push(a[i].cusNum);
                }            
            }
        }
        cur++;
    }
    for(int i = 0;i<K;i++){
        if(vec[i].aNum == A && vec[i].bNum == B){
            ans += vec[i].num;
        }
    }
    if(ans > 0)
        return ans;
    else 
        return -1;
}
int main(){
    freopen("input.txt","r",stdin);
    int T;
    cin >> T;
    for(int t = 1; t<= T;t++){
        cin >> N >> M >> K >> A >> B;
        for(int i = 0;i<N;i++){
            cin >> a[i].t;
        }
        for(int i = 0;i<M;i++){
            changu cg;            
            cin >> b[i].t;
        }
        for(int i = 0;i<K;i++){
            customer cu;
            cin >> cu.t;
            cu.num = i+1;
            cu.state = 0;
            vec.push_back(cu);
        }
        //solve();
        cout<<"#"<<t<<" "<<solve()<<endl;
        vec.clear();
    }
}