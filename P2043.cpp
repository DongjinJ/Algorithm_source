#include <iostream>

using namespace std;

int main()
{
    int P, K;
    int answer = 0;

    scanf("%d %d", &P, &K);

    if (K > P)
        answer = -1;
    else
        answer = P - K + 1;

    printf("%d\n", answer);

    return 0;
}