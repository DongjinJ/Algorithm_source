#include <iostream>

using namespace std;

int main()
{
    long long X;

    scanf("%lld", &X);

    long long i = 1;
    while (X > 0){
        X -= i;
        i++;
    }
    i--;
    X += i;

    if(i % 2 == 0)
        printf("%lld/%lld\n", X, i - X + 1);
    else
        printf("%lld/%lld\n", i - X + 1, X);

    return 0;
}