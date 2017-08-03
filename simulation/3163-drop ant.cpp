#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    int T,N,L,K;
    int pos,id;
    vector<pair<int,int> > ant;
    deque<int> antId;
    vector<pair<int, int> > res;
    scanf("%d",&T);

    while(T > 0){
        ant.clear();
        antId.clear();
        scanf("%d %d %d",&N,&L,&K);
        ant = vector<pair<int, int> >(N);
        res = vector<pair<int, int> >(N);
        
        for(int i = 0;i<N;i++){
            scanf("%d %d",&pos,&id);
            if(id > 0){
                pos = L - pos;
            }
            ant[i].first = pos;
            ant[i].second = id;
            antId.push_back(ant[i].second);
        }
        sort(ant.begin(),ant.end());
        /*for(int i = 0;i<N;i++){
            printf("ss%d %d\n",ant[i].first,ant[i].second);
        }*/

        for(int i = 0;i<N;i++){
            res[i].first = ant[i].first;
            if(ant[i].second > 0){
                //res.push_back(make_pair(dis,antId.back()));
                res[i].second = antId.back();
                antId.pop_back();
            }else{
                res[i].second = antId.front();
                antId.pop_front();
            }
            //printf("%d\n",res);
        }

        sort(res.begin(),res.end());
        /*for(int i = 0;i<N;i++){
            printf("%d %d\n",res[i].first,res[i].second);
        }*/
        printf("%d\n",res[K-1].second);        
        T--;
    }
}