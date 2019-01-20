#include <iostream>

using namespace std;

int main()
{
    int T, a, b;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &a, &b);
        printf("#%d %d %d\n", i + 1, a / b, a % b);
    }

    return 0;
}