#include <cstdio>
#include <list> //list header
#include <functional> //iterator header
using namespace std;

int main(){
    list<int> li; //리스트 선언
    list<int>::iterator it; //반복자 선언

    for(int i = 0;i < 10;i++){
        li.push_back(i); //뒤쪽으로 원소를 0부터 9까지 넣음
    }

    for(it = li.begin();it != li.end();it++){ //it이 li.begin()을 가리킴, it이 li.end()를 가리키지 않을때까지 반복, it가 다음것을 가리킴
        printf("%d ",*it); //원소 접근은 *it을 이용
    }
    printf("\n");
} 
