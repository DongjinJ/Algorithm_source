#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int word = 0;
    cin >> str;

    for(int i = 0;i < str.size();i++){
        if(str[i] == 'c'){
            if(str[i+1] == '='){
                i++;
                word++;
            }                   // ũ�ξ�Ƽ�� ���� "c="�� ���
            else if(str[i+1] == '-'){
                i++;
                word++;
            }                   // ũ�ξ�Ƽ�� ���� "c-"�� ���
            else
                word++;         // �Ϲ� ���ĺ� "c"�� ���
        }
        else if(str[i] == 'd'){
            if(str[i+1] == 'z' && str[i+2] == '='){
                i += 2;
                word++;
            }                   // ũ�ξ�Ƽ�� ���� "dz="�� ���
            else if(str[i+1] == '-'){
                i++;
                word++;
            }                   // ũ�ξ�Ƽ�� ���� "d-"�� ���
            else
                word++;
        }                       // �Ϲ� ���ĺ� "d"�� ���
        else if(str[i] == 'l'){
            if(str[i+1] == 'j'){
                i++;
                word++;
            }                   // ũ�ξ�Ƽ�� ���� "lj"�� ���
            else
                word++;         // �Ϲ� ���ĺ� "l"�� ���
        }
        else if(str[i] == 'n'){
            if(str[i+1] == 'j'){
                i++;
                word++;
            }                   // ũ�ξ�Ƽ�� ���� "nj"�� ���
            else
                word++;         // �Ϲ� ���ĺ� "n"�� ���
        }
        else if(str[i] == 's'){
            if(str[i+1] == '='){
                i++;
                word++;
            }                   // ũ�ξ�Ƽ�� ���� "s="�� ���
            else
                word++;         // �Ϲ� ���ĺ� "s"�� ���
        }
        else if(str[i] == 'z'){
            if(str[i+1] == '='){
                i++;
                word++;
            }                   // ũ�ξ�Ƽ�� ���� "z="�� ���
            else
                word++;         // �Ϲ� ���ĺ� "z"�� ���
        }
        else
            word++;             // �Ϲ� ���ĺ��� ���
    }

    printf("%d\n", word);

    return 0;
}