#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int map[11][11];
int N, M;
int ans = 99999;
int stairNum[11];
typedef struct door {
	int x;
	int y;
	int h;
}door;
vector<pair<int, int> > p;
vector<door> s;
void calc() {
	pair<int,int> remainDis[11] = {};
    int stairIdx[2] = {};
    vector<int> stairPool[2];
	for (int i = 0; i<M; i++) {
        //거리계산
		remainDis[i].first = fabs(s[stairNum[i]].x - p[i].first) + fabs(s[stairNum[i]].y - p[i].second);
        remainDis[i].second = stairNum[i];
    }
    sort(remainDis,remainDis+M);

    int cur = 1;
	int cnt = 0;
	for(cur = 1;cur <= 20; cur++) {
        if(cnt == M) {
        	ans = min(ans, cur-1);
            return;
        }
        //계단별 계산
		for (int i = 0; i<2; i++) {
            if(stairPool[i].size() > 0){
                for (int j = stairIdx[i]; j< stairIdx[i] + 3; j++) {
                    if( j >= stairPool[i].size()) break;
                    if(stairPool[i][j] > 0){
                        //한칸씩 내려감   
                        stairPool[i][j]--;
                    }
                    if(stairPool[i][j] == 0){
                        //계단 다 내려오면 카운트
                        stairIdx[i]++;
                        cnt++;
                    }
                }
            }
		}
        
		for (int i = 0; i<M; i++) {
            //계단에 도착할 시간
            if(cur == remainDis[i].first){
                int sn = remainDis[i].second;
                //계단 높이 + 내려가는거 대기시간(1)
                stairPool[sn].push_back(s[sn].h+1);
            }
		}
	}
}
void dfs(int depth) {
	if (depth == M) {
		calc();
	}
	else {
		for (int i = 0; i<2; i++) {
			stairNum[depth] = i;
			dfs(depth + 1);
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int doorNum = 0;
		scanf("%d", &N);
		for (int i = 0; i<N; i++) {
			for (int j = 0; j<N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1) p.push_back(make_pair(i, j));
				else if (map[i][j] > 0) {
					door dr;
					dr.x = i;
					dr.y = j;
					dr.h = map[i][j];
					//dr.wait = 0;
					//memset(dr.pool, 0, sizeof(dr.pool));
					s.push_back(dr);
				}
			}
		}
		M = p.size();
		dfs(0);
		printf("#%d %d\n", t, ans);
		p.clear();
		s.clear();
		ans = 99999;
	}
}