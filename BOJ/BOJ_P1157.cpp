#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string Q;
    char answer;
    int alpha[26];                                  // 알파벳 개수 체크 배열

    memset(alpha, 0, sizeof(alpha));                // 0으로 초기화

    cin >> Q;

    int max = 0;                                    // 최대 값 저장
    for(int i = 0;i < Q.size();i++){
        if(Q[i] >= 'a' && Q[i] <= 'z'){             // 소문자일 경우
            alpha[Q[i] - 'a']++;
            if(alpha[Q[i]- 'a'] > max)              // 최대값이 현재 문자열보다 작을 경우 최대값 최신화
                max = alpha[Q[i] - 'a'];
        }
        else if(Q[i] >= 'A' && Q[i] <= 'Z'){        // 대문자일 경우
            alpha[Q[i] - 'A']++;
            if(alpha[Q[i]- 'A'] > max)              // 최대값이 현재 문자열보다 작을 경우 최대값 최신화
                max = alpha[Q[i] - 'A'];

        }
        else
            ;

    }
    int count = 0;                                  // 가장 많이 사용된 알파벳의 개수
    for(int i = 0;i < 26;i++){
        if(max == alpha[i]){
            answer = i + 'A';                       // 가장 많이 사용된 알파벳 저장
            count++;
        }
        else
            ;
    }
    if(count > 1)
        answer = '?';                               
    else
        ;

    printf("%c", answer);
    
    return 0;
}