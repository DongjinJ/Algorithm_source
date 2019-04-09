#include <iostream>

using namespace std;

int gcd(int a, int b){
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}               // ��Ŭ���� ȣ�������� �ִ����� ���ϱ�
int lcm(int a, int b){
    return a * b / gcd(a, b);
}               // �ִ������� �̿��� �ּҰ���� ���ϱ�
int main(){
    int T;

    scanf("%d", &T);

    for(int i = 0;i < T;i++){
        int x, y, M, N;
        scanf("%d %d %d %d", &M, &N, &x, &y);

        int limit = lcm(M, N);                  // Ž���� �ִ� ������ ����(M�� N�� �ּҰ����)
        int cycle = x;                          // ù��° �ڸ��� ���� ����
        int answer = -1;                        // ã�� ���� ��� ���� �ȹٲ�Ƿ� -1 ���
        while(cycle <= limit){
            int comp = 0;
            if(cycle % N == 0)
                comp = N;                       // �ι�° �ڸ����� M��ŭ ���������� N���� �������� ��, ������ ������ ��� N
            else
                comp = cycle % N;               // �ι�° �ڸ����� M��ŭ ���������� N���� �������� ��, ������ �������� ���� ��� ��������

            if(y == comp){
                answer = cycle;
                break;
            }                                   // ���� ������ �ι�° ���� y�� ������ Ž�� ���� �� ���� ���� ����
            else
                cycle += M;                     // ���� ���� ��� Ž�� ������ ���� M��ŭ ����
        }
        printf("%d\n", answer);                 // ����� ���
    }
}