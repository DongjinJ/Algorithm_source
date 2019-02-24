#include <iostream>

using namespace std;

int main(){
    int answer = 0;

    for(int i = 0;i < 5;i++){
        int temp;
        scanf("%d", &temp);
        if(temp < 40)
            answer += 40;           // 40점 이하는 보충학습을 통해 40점을 받게됨
        else
            answer += temp;         // 그 이외에는 본인 점수 입력
    }
    answer /= 5;            // 인원 수 만큼 나누기(평균)

    printf("%d\n", answer);

    return 0;

}