#include <iostream>

using namespace std;

int main(){
    int N;

    scanf("%d", &N);

    for(int i = N;i >= 0;i--)
        printf("%d ", i);
    printf("\n");

    return 0;
}