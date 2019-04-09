#include <iostream>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;

int main(){
    string N;
    int number[10];
    memset(number, 0, sizeof(number));
    cin >> N;

    int max = 0;
    for(int i = 0;i < N.size();i++)
        number[N[i] - '0']++;

    number[6] = (int)ceil((float)(number[9] + number[6]) / 2);
    number[9] = 0;

    for(int i = 0;i < 9;i++){
        if(max < number[i])
            max = number[i];
        else
            ;
    }

    printf("%d\n", max);
    
    return 0;
}