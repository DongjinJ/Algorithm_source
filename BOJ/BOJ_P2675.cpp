#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int T;

    scanf("%d", &T);

    for(int i = 0;i < T;i++){
        int rep;                    // 반복하는 횟수
        scanf("%d", &rep);
        string code;                
        cin >> code;                // 문자열 입력

        for(int j = 0;j < code.size();j++)
            for(int k = 0;k < rep;k++)
                printf("%c", code[j]);              // 반복 횟수만큼 각 문자를 반복 출력
        printf("\n");
    }
    
    return 0;
}