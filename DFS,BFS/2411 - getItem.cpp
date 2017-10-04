#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int map[101][101] = {};

int getLoadNum(pair<int, int> n, pair<int, int> m){
    int dp[101][101];
    int x1 = n.first;
    int y1 = n.second;
    int x2 = m.first;
    int y2 = m.second;
    //printf("position:%d %d %d %d\n",y1,x1,y2,x2);
    for(int i = x1;i<=x2;i++){
        if(map[i][y1] == -1)break;
        dp[i][y1] = 1;
    }
    for(int i = y1;i<=y2;i++){
        if(map[x1][i] == -1)break;        
        dp[x1][i] = 1;
    }
    for(int i = x1+1;i<=x2;i++){
        for(int j = y1+1;j<=y2;j++){
        	if(map[i][j] != -1)
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    /*for(int i = y1;i<=y2;i++){
        for(int j = x1;j<=x2;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    
    return dp[x2][y2];
}
int main(){
    int N,M,A,B;
    vector<pair<int, int> > aSpot;
    scanf("%d%d%d%d",&N,&M,&A,&B);
    int x,y;
    for(int i = 0;i<A;i++){
        scanf("%d%d",&x,&y);
        aSpot.push_back(make_pair(x-1,y-1));
    }
    aSpot.push_back(make_pair(0,0));
    aSpot.push_back(make_pair(N-1,M-1));
    sort(aSpot.begin(),aSpot.end());
    for(int i = 0;i<B;i++){
        scanf("%d%d",&x,&y);
        map[x-1][y-1] = -1;        
    }
    int answer = 1;
    for(int i = 0;i<aSpot.size()-1;i++){
        int tp = getLoadNum(aSpot[i],aSpot[i+1]);
        //printf("dd%d\n",tp);
        answer *= tp;
        
    } 
    printf("%d\n",answer);
}