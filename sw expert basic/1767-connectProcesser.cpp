#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int mx = 1e9;
int N;
int map[13][13];
vector<pair<int, int> > vec;
void printMap(){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
     }
     cout<<endl;
     //exit(0);
}
void setMap(int x, int y,int dir){
    int i = x;
    int j = y;
    while(i>0 && j > 0 && i < N && j < N){
        switch(dir){
            case 0: i++;break;
            case 1: i--;break;
            case 2: j++;break;
            case 3: j--;
        }
        map[i][j] = 2;
    }
    //printMap();
}
void delMap(int x, int y,int dir){
    int i = x;
    int j = y;
    while(i>0 && j > 0 && i < N && j < N){
        switch(dir){
            case 0: i++;break;
            case 1: i--;break;
            case 2: j++;break;
            case 3: j--;
        }
        map[i][j] = 0;
    }
}
bool promising(int x, int y,int dir){
    int i = x;
    int j = y;
    //cout<<i<<","<<j<<","<<dir<<endl;
    bool flag = true;
    while(i>0 && j > 0 && i < N && j < N){
        switch(dir){
            case 0: i++;break;
            case 1: i--;break;
            case 2: j++;break;
            case 3: j--;
        }
        //cout<<"dd"<<i<<","<<j<<","<<dir<<","<<map[i][j]<<endl;
        
        if(map[i][j] != 0){
            flag = false;
            break;
        }
    }
    return flag;
}
bool promising2(int x,int y){
    int i = x;
    int j = y;
    int k = x;
    int l = y;
    //cout<<i<<","<<j<<","<<dir<<endl;
    bool a[4] = {false,};
    bool flag = false;
    while(i < N){
        i++;
        if(map[i][y] == 1){
            a[0] = true;
        }
    }
    while(j < N){
        j++;
         if(map[x][j] == 1){
            a[1] = true;
        }
    }
    while(k > 0){
        k--;
        if(map[k][y] == 1){
            a[2] = true;
        }
    }
    while(l > 0){
        l--;
        if(map[x][l] == 1){
            a[3] = true;
        }
    }
    for(int i = 0;i<4;i++){
        if(a[i] == false){
            flag = true;
            break;
        }
    }
    return flag;
}
void getRes(){
    int res = 0;
     for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(map[i][j] == 2){
                res++;
            }
        }
     }
    if(mx > res){
        mx = res;
    }
    //cout<<res<<endl;
}
void back(int n){
    int x = vec[n].first;
    int y = vec[n].second;
    if(promising2(x,y)){
        for(int i = 0;i<4;i++){
            if(promising(x,y,i)){
                if(n == vec.size()){
                    getRes();
                }else{
                    setMap(x,y,i);
                    back(n+1);
                    delMap(x,y,i);                
                }
            }
        }
    }
    else
    {
        if (n == vec.size())
        {
            getRes();
        }
        else
        {
            back(n + 1);
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    
    for(int i = 1;i<=T;i++){
        vec.erase(vec.begin(),vec.end());
        //cout<< vec.size()<<endl;
        scanf("%d",&N);

        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                scanf("%d",&map[i][j]);
                if(i > 0 && j > 0 && i < N-1 && j < N-1 && map[i][j] == 1){
                    vec.push_back(make_pair(i,j));
                }
            }
        }
        back(0);
        if(mx == 1e9)
            mx = 0;
        printf("#%d %d\n",i,mx);
        mx = 1e9;
    }
}