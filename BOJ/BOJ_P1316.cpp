#include <iostream>
#include <string.h>

using namespace std;

int main() {

    string group;                                       // 체크할 문자열
    int answer = 0;                                     // 그룹 문자열의 개수
    int T;                                              // 반복 횟수

    scanf("%d", &T);

    for(int i = 0;i < T;i++){
        cin >> group;

        bool wrong = false;                             // 정답이 아닐 경우 true
        bool alpha[26];                                 // 해당 알파벳이 이미 반복되어 쓰였는지 체크
        memset(alpha, false, sizeof(alpha));            // alpha배열 false로 초기화

        for(int j = 0;j < group.size();j++){
            if(alpha[group[j] - 'a']){
                wrong = true;
                break;
            }                                           // 이미 반복된 문자인데 다시 쓰인 경우 wrong
            else{
                alpha[group[j] - 'a'] = true;           // 반복됨을 체크
                char key = group[j];                    // 해당 문자 임시 저장
                while(true){
                    if(group[j] == key)
                        j++;
                    else
                        break;
                }                                       // 반복이 끝날때까지 탐색
                j--;                                    // 탐색 종료지점이 반복이 끝나고 1개 더 증가해 있기때문에 1감소
            }
        }                                               // 아직 쓰이지 않은 문자인 경우
        if(wrong)
            ;
        else
            answer++;                                   // 틀리지 않았을 경우만 답 1증가
    }
    
    printf("%d", answer);

    return 0;
}