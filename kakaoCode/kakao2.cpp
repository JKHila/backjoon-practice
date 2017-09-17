#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T > 0){
        string myStr;
        cin >> myStr;
        string score[3];
        int sIdx = 0;
        for(int i = 0;i<myStr.length();i++){
            int a = myStr[i];
            if(a >= 48 && a <= 57){
                score[sIdx] += myStr[i];
                a = myStr[i+1];
                if(a == 48){
                    i++;
                    score[sIdx] += myStr[i]; 
                    a = myStr[i+1];            
                }
                while(a < 48 || a > 57){
                    if(i >= myStr.length()) break;
                    i++;
                    score[sIdx] += myStr[i];
                    a = myStr[i+1];
                }
                sIdx++;
            }
        }
        for(int i = 0;i<3;i++){
            //cout<< score[i] <<endl;
        }
        int s[3] = {0};
        int answer = 0;
        for(int i = 0;i<3;i++){
            int it = 1;
            if(score[i][1] != '0')
                s[i] = score[i][0] - 48;
            else{
                s[i] = 10;
                it++;
            }
            //cout<<"s[i]"<<s[i]<<endl;
            if(score[i][it]== 'D'){
                s[i] = pow(s[i],2);
            }else if(score[i][it] == 'T'){
                s[i] = pow(s[i],3);
            }
            it++;

            if(score[i].length() > 2){
                //cout<<"fu"<<score[i][2]<<endl;
                if(score[i][it] == '#'){
                    s[i] *= -1;
                }else if(score[i][it] == '*'){
                    if(i > 0){
                        s[i] *= 2;
                        s[i-1] *= 2;
                    }else{
                        s[i] *= 2;
                    }
                }
            }
        }
        for(int i = 0;i<3;i++){
            answer += s[i];
            //cout<<"AA"<<s[i]<<endl;
        }
        cout <<answer<<endl;
        T--;
    }
}