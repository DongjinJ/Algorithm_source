#include <iostream>

using namespace std;

int main(){
    char pattern[5][5];

    

    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++)
            pattern[i][j] = '+';
        pattern[i][i] = '#';
    }

    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++)
            printf("%c", pattern[i][j]);
        printf("\n");
    }

    return 0;
}
