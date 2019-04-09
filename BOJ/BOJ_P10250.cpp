#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++){
        int H, W, N;
        scanf("%d %d %d", &H, &W, &N);

        int answer;
        if(N % H == 0){
            answer = H * 100;       // 방 번호 층수 계산
            answer += N / H;        // 방 번호 호수 계산
        }               // 손님 입장 번호가 건물의 최대 층수와 나누어 떨어지는 경우
        else{
            answer = (N % H) * 100; // 방 번호 층수 계산
            answer += N / H + 1;    // 방 번호 호수 계산
        }               // 손님 입장 번호가 건물의 최대 층수와 나누어 떨어지지 않는 경우

        

        printf("%d\n", answer);
    }

    return 0;
}