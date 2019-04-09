#include <iostream>
#include <string.h>

using namespace std;

int dp[15][14];                                     // 연산 결과 값을 저장하기 위한 변수

int room(int k, int n){
    // cout << "k: " << k << "\tn: " << n << "\tcurrent: " << dp[k][n-1] << endl;
    if (dp[k][n - 1] < 0){
        if (k == 0)
            dp[k][n - 1] = n;                       // 0층 n호는 n명 살 수 있음 (주어진 조건)
        else if (n == 1)
            dp[k][n - 1] = 1;                       // 1호는 1명 살 수 있음 (주어진 조건)
        else
            dp[k][n - 1] = room(k, n - 1) + room(k - 1, n);             // k층 n호는 k층 n-1호와 k-1층 n호의 합으로 구할 수 있음
    }                                               // 해당 k층 n-1호가 계산이 안됐을 경우 계산 진행
    
    return dp[k][n - 1];                            // 계산한 값을 return
}
int main(){
    memset(dp, -1, sizeof(dp));                     // 중복 연산을 판별하기 위해 -1로 초기화

    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++){
        int k, n;
        scanf("%d", &k);
        scanf("%d", &n);

        printf("%d\n", room(k, n));
    }

    return 0;
}