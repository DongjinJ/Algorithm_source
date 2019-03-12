#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string problem;         // 입력 받을 문자열 
    int alpha[26];          // 알파벳 체크 
    memset(alpha, -1, sizeof(alpha));           // alpha배열을 모두 -1로 초기화

    cin >> problem;         // 문자열 입력

    for(int i = 0;i < problem.size();i++){
        if(alpha[problem[i] - 'a'] == -1)
            alpha[problem[i] - 'a'] = i;        // 처음 온 알파벳의 index를 저장 (만약 이미 index가 저장되어있다면 실행 x)

        else
            ;
    }

    for(int i = 0;i < 26;i++)
        printf("%d ", alpha[i]);
    printf("\n");

    return 0;
}