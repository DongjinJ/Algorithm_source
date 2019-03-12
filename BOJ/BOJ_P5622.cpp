#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string dial;                        // 입력 받을 문자열
    int total_time = 0;                 // 다이얼을 누른데 총 걸린 시간
    cin >> dial;

    for(int i = 0;i < dial.size();i++){
        if(dial[i] - 'A' >= 0 && dial[i] - 'A' <= 2)
            total_time += 3;            // 2 (걸린 시간: 3초)
        else if(dial[i] - 'A' >= 3 && dial[i] - 'A' <= 5)
            total_time += 4;            // 3 (걸린 시간: 4초)
        else if(dial[i] - 'A' >= 6 && dial[i] - 'A' <= 8)
            total_time += 5;            // 4 (걸린 시간: 5초) 
        else if(dial[i] - 'A' >= 9 && dial[i] - 'A' <= 11)
            total_time += 6;            // 5 (걸린 시간: 6초)
        else if(dial[i] - 'A' >= 12 && dial[i] - 'A' <= 14)
            total_time += 7;            // 6 (걸린 시간: 7초)
        else if(dial[i] - 'A' >= 15 && dial[i] - 'A' <= 18)
            total_time += 8;            // 7 (걸린 시간: 8초)
        else if(dial[i] - 'A' >= 19 && dial[i] - 'A' <= 21)
            total_time += 9;            // 8 (걸린 시간: 9초)
        else if(dial[i] - 'A' >= 22 && dial[i] - 'A' <= 25)
            total_time += 10;           // 9 (걸린 시간: 10초)
        else
            ;
    }

    printf("%d\n", total_time);

    return 0;
}