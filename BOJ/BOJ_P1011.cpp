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
            j++;            // ������ �Ǵ� ���� ã��
        
        j--;                // ������ ����� ���� ��
        long long left = distance - j*j;                // ������ ��ŭ �̵��ϰ� ���� �Ÿ�
        long long answer = 0;
        if(left == 0)
            answer = 2*j - 1;                           // �̵� �Ÿ��� �������� ���
        else{
            if(left <= j)
                answer = 2*j;                           // ���� �Ÿ� + 1�� ���ֿ� ���� ���
            else
                answer = 2*j + 1;                       // ���� �Ÿ� + 2�� ���ֿ� ���� ���
        }
            
        
        printf("%lld\n", answer);
    }

    return 0;
}