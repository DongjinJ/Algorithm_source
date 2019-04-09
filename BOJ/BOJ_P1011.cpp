#include <iostream>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 0;i < T;i++){
        long long x, y;
        scanf("%lld %lld", &x, &y);
        long long distance = y - x;

        long long j = 1;
        while(distance - j*j > 0)
            j++;            // 음수가 되는 지점 찾기
        
        j--;                // 음수로 만들기 직전 값
        long long left = distance - j*j;                // 제곱수 만큼 이동하고 남은 거리
        long long answer = 0;
        if(left == 0)
            answer = 2*j - 1;                           // 이동 거리가 제곱수일 경우
        else{
            if(left <= j)
                answer = 2*j;                           // 남은 거리 + 1의 범주에 있을 경우
            else
                answer = 2*j + 1;                       // 남은 거리 + 2의 범주에 있을 경우
        }
            
        
        printf("%lld\n", answer);
    }

    return 0;
}