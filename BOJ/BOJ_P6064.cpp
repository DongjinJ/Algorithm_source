#include <iostream>

using namespace std;

int gcd(int a, int b){
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}               // 유클리드 호제법으로 최대공약수 구하기
int lcm(int a, int b){
    return a * b / gcd(a, b);
}               // 최대공약수를 이용해 최소공배수 구하기
int main(){
    int T;

    scanf("%d", &T);

    for(int i = 0;i < T;i++){
        int x, y, M, N;
        scanf("%d %d %d %d", &M, &N, &x, &y);

        int limit = lcm(M, N);                  // 탐색할 최대 범위를 지정(M과 N의 최소공배수)
        int cycle = x;                          // 첫번째 자리의 숫자 지정
        int answer = -1;                        // 찾지 못할 경우 값이 안바뀌므로 -1 출력
        while(cycle <= limit){
            int comp = 0;
            if(cycle % N == 0)
                comp = N;                       // 두번째 자리수가 M만큼 진행했을때 N으로 나누었을 때, 나누어 떨어질 경우 N
            else
                comp = cycle % N;               // 두번째 자리수가 M만큼 진행했을때 N으로 나누었을 때, 나누어 떨어지지 않을 경우 나머지값

            if(y == comp){
                answer = cycle;
                break;
            }                                   // 현재 진행한 두번째 값이 y와 같으면 탐색 종료 후 현재 순번 저장
            else
                cycle += M;                     // 같지 않을 경우 탐색 진행을 위해 M만큼 더함
        }
        printf("%d\n", answer);                 // 결과값 출력
    }
}