#include <vector>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int dp[501][501] = {};
    for(int i = 0;i<n;i++){
        if(city_map[0][i] == 1)
            break;
        dp[0][i] = 1;
    }
    for(int i = 0;i<m;i++){
        if(city_map[i][0] == 1)
            break;
        dp[i][0] = 1;
    }
    
    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            if(city_map[i][j] == 1){
                continue;
            }else{
                for(int k = j-1;k >= 0;k--){
                    if(city_map[i][k] == 1){
                        break;
                    }
                    if(city_map[i][k] == 0){
                        dp[i][j] += dp[i][k];
                        dp[i][j] %= MOD;
                        break;
                    }
                }
                for(int k = i-1;k >= 0;k--){
                    if(city_map[k][j] == 1){
                        break;
                    }
                    if(city_map[k][j] == 0){
                        dp[i][j] += dp[k][j];
                        dp[i][j] %= MOD;
                        break;
                    }
                }
            }
        }
    }
    answer = dp[m-1][n-1] %= MOD;
    return answer;
}