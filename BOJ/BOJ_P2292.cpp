#include <iostream>

using namespace std;

int main(){
    int start;

    scanf("%d", &start);

    int i = 0;      // 6에 곱해줄 값
    int answer = 0; // 출력 값

    while(start > 0){
        if(i == 0)  // 처음 시작은 1을 빼줌
            start -= 1;
        else        // 6의 배수로 빼줌
            start -= (i*6);
        i++;
    }           // 빼준 결과물이 음수일 경우 반복문 탈출
    answer = i;
    printf("%d\n", answer);

    return 0;
}