#include <iostream>
#include <string.h>

using namespace std;

int dp[15][14];                                     // ���� ��� ���� �����ϱ� ���� ����

int room(int k, int n){
    // cout << "k: " << k << "\tn: " << n << "\tcurrent: " << dp[k][n-1] << endl;
    if (dp[k][n - 1] < 0){
        if (k == 0)
            dp[k][n - 1] = n;                       // 0�� nȣ�� n�� �� �� ���� (�־��� ����)
        else if (n == 1)
            dp[k][n - 1] = 1;                       // 1ȣ�� 1�� �� �� ���� (�־��� ����)
        else
            dp[k][n - 1] = room(k, n - 1) + room(k - 1, n);             // k�� nȣ�� k�� n-1ȣ�� k-1�� nȣ�� ������ ���� �� ����
    }                                               // �ش� k�� n-1ȣ�� ����� �ȵ��� ��� ��� ����
    
    return dp[k][n - 1];                            // ����� ���� return
}
int main(){
    memset(dp, -1, sizeof(dp));                     // �ߺ� ������ �Ǻ��ϱ� ���� -1�� �ʱ�ȭ

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