#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main()
{
    string A, B;

    cin >> A >> B;

    string temp;            // ������ ���ڿ��� �ӽ÷� �����ϴ� ����
    for (int i = A.size() - 1; i < A.size(); i--){
        temp += A[i];
    }               // A�� �� �� ���ڸ� Ž���� �ӽ� ������ �պ��� ����
    A = temp;       // �ӽ� ������ A�� �����
    temp = "";      // �ӽ� ���� �ʱ�ȭ
    for (int i = B.size() - 1; i < B.size(); i--){
        temp += B[i];
    }               // B�� �� �� ���ڸ� Ž���� �ӽ� ������ �պ��� ����
    B = temp;       // �ӽ� ������ B�� �����
    temp = "";      // �ӽ� ���� �ʱ�ȭ

    if(atoi(A.c_str()) > atoi(B.c_str()))           // string type�� char* type���� �ٲ� �� int������ ��ȯ�� ��Һ�
        printf("%s\n", A.c_str());                  // A�� Ŭ ���
    else
        printf("%s\n", B.c_str());                  // B�� Ŭ ���

    return 0;
}