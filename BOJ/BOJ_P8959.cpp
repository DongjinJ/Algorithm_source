#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;

    scanf("%d", &T);

    for(int i = 0;i < T;i++){
        string problem;
        int score = 0;      // 현재 누적된 점수를 저장하는 변수
        int answer = 0;

        cin >> problem;

        for(int j = 0;j < problem.size();j++){
            if(problem[j] == 'O')
                score++;       // 정답을 맞을때마다 누적 점수를 1점씩 증가시킨다
            else
                score = 0;      // 오답일 경우 누적 점수를 0점으로 초기화
            answer += score;    // 현재 누적 점수를 정답에 더해준다
        }

        printf("%d\n", answer);
    }

    return 0;
}