#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string dial;                        // �Է� ���� ���ڿ�
    int total_time = 0;                 // ���̾��� ������ �� �ɸ� �ð�
    cin >> dial;

    for(int i = 0;i < dial.size();i++){
        if(dial[i] - 'A' >= 0 && dial[i] - 'A' <= 2)
            total_time += 3;            // 2 (�ɸ� �ð�: 3��)
        else if(dial[i] - 'A' >= 3 && dial[i] - 'A' <= 5)
            total_time += 4;            // 3 (�ɸ� �ð�: 4��)
        else if(dial[i] - 'A' >= 6 && dial[i] - 'A' <= 8)
            total_time += 5;            // 4 (�ɸ� �ð�: 5��) 
        else if(dial[i] - 'A' >= 9 && dial[i] - 'A' <= 11)
            total_time += 6;            // 5 (�ɸ� �ð�: 6��)
        else if(dial[i] - 'A' >= 12 && dial[i] - 'A' <= 14)
            total_time += 7;            // 6 (�ɸ� �ð�: 7��)
        else if(dial[i] - 'A' >= 15 && dial[i] - 'A' <= 18)
            total_time += 8;            // 7 (�ɸ� �ð�: 8��)
        else if(dial[i] - 'A' >= 19 && dial[i] - 'A' <= 21)
            total_time += 9;            // 8 (�ɸ� �ð�: 9��)
        else if(dial[i] - 'A' >= 22 && dial[i] - 'A' <= 25)
            total_time += 10;           // 9 (�ɸ� �ð�: 10��)
        else
            ;
    }

    printf("%d\n", total_time);

    return 0;
}