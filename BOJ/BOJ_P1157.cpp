#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string Q;
    char answer;
    int alpha[26];                                  // ���ĺ� ���� üũ �迭

    memset(alpha, 0, sizeof(alpha));                // 0���� �ʱ�ȭ

    cin >> Q;

    int max = 0;                                    // �ִ� �� ����
    for(int i = 0;i < Q.size();i++){
        if(Q[i] >= 'a' && Q[i] <= 'z'){             // �ҹ����� ���
            alpha[Q[i] - 'a']++;
            if(alpha[Q[i]- 'a'] > max)              // �ִ밪�� ���� ���ڿ����� ���� ��� �ִ밪 �ֽ�ȭ
                max = alpha[Q[i] - 'a'];
        }
        else if(Q[i] >= 'A' && Q[i] <= 'Z'){        // �빮���� ���
            alpha[Q[i] - 'A']++;
            if(alpha[Q[i]- 'A'] > max)              // �ִ밪�� ���� ���ڿ����� ���� ��� �ִ밪 �ֽ�ȭ
                max = alpha[Q[i] - 'A'];

        }
        else
            ;

    }
    int count = 0;                                  // ���� ���� ���� ���ĺ��� ����
    for(int i = 0;i < 26;i++){
        if(max == alpha[i]){
            answer = i + 'A';                       // ���� ���� ���� ���ĺ� ����
            count++;
        }
        else
            ;
    }
    if(count > 1)
        answer = '?';                               
    else
        ;

    printf("%c", answer);
    
    return 0;
}