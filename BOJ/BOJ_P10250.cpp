#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++){
        int H, W, N;
        scanf("%d %d %d", &H, &W, &N);

        int answer;
        if(N % H == 0){
            answer = H * 100;       // �� ��ȣ ���� ���
            answer += N / H;        // �� ��ȣ ȣ�� ���
        }               // �մ� ���� ��ȣ�� �ǹ��� �ִ� ������ ������ �������� ���
        else{
            answer = (N % H) * 100; // �� ��ȣ ���� ���
            answer += N / H + 1;    // �� ��ȣ ȣ�� ���
        }               // �մ� ���� ��ȣ�� �ǹ��� �ִ� ������ ������ �������� �ʴ� ���

        

        printf("%d\n", answer);
    }

    return 0;
}