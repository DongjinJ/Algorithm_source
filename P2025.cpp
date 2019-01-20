#include <iostream>

using namespace std;

int main(){
    int T;
    int answer = 0;
    scanf("%d", &T);

    for(int i = 1;i <= T;i++)
        answer += i;

    printf("%d", answer);

    return 0;
}