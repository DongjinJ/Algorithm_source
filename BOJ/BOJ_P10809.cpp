#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string problem;         // �Է� ���� ���ڿ� 
    int alpha[26];          // ���ĺ� üũ 
    memset(alpha, -1, sizeof(alpha));           // alpha�迭�� ��� -1�� �ʱ�ȭ

    cin >> problem;         // ���ڿ� �Է�

    for(int i = 0;i < problem.size();i++){
        if(alpha[problem[i] - 'a'] == -1)
            alpha[problem[i] - 'a'] = i;        // ó�� �� ���ĺ��� index�� ���� (���� �̹� index�� ����Ǿ��ִٸ� ���� x)

        else
            ;
    }

    for(int i = 0;i < 26;i++)
        printf("%d ", alpha[i]);
    printf("\n");

    return 0;
}