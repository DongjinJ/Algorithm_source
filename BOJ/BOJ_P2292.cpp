#include <iostream>

using namespace std;

int main(){
    long long start;

    scanf("%lld", &start);

    int i = 0;
    int answer = 0;

    while(start > 0){
        if(i == 0)
            start -= 1;
        else
            start -= (i*6);
        i++;
        answer++;
    }

    printf("%d\n", answer);

    return 0;
}