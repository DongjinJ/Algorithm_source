#include <iostream>

using namespace std;

int main(){
    int N;

    scanf("%d", &N);

    int answer = 1;

    for(int i = 0;i <= N;i++){
        printf("%d ", answer);
        answer *= 2;
    }

    return 0;
}