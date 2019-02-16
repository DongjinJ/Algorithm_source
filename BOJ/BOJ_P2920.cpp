#include <iostream>

using namespace std;

int main()
{
    int note[8];        // 음계를 저장할 변수

    for (int i = 0; i < 8; i++)
        scanf("%d", &note[i]);

    if(note[0] == 1){
        bool ascending = true;
        for(int i = 1;i < 8;i++){
            if(note[i] != i + 1){
                ascending = false;
                break;
            }
        }
        if(ascending)
            printf("ascending\n");
        else
            printf("mixed\n");
    }       // 첫음계가 1부터 시작할때 ascending인지 판별

    else if(note[0] == 8){
        bool descending = true;
        for(int i = 1;i < 8;i++){
            if(note[i] != 8 - i){
                descending = false;
                break;
            }
        }
        if(descending)
            printf("descending\n");
        else
            printf("mixed\n");
    }       // 첫음계가 8부터 시작할때 descending인지 판별

    else
        printf("mixed\n");      // 그 이외의 모든 경우
    

    return 0;
}