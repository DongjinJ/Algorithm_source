#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int T;

    scanf("%d", &T);

    for(int i = 0;i < T;i++){
        int rep;                    // �ݺ��ϴ� Ƚ��
        scanf("%d", &rep);
        string code;                
        cin >> code;                // ���ڿ� �Է�

        for(int j = 0;j < code.size();j++)
            for(int k = 0;k < rep;k++)
                printf("%c", code[j]);              // �ݺ� Ƚ����ŭ �� ���ڸ� �ݺ� ���
        printf("\n");
    }
    
    return 0;
}