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
            }                   // 크로아티아 문자 "c="일 경우
            else if(str[i+1] == '-'){
                i++;
                word++;
            }                   // 크로아티아 문자 "c-"일 경우
            else
                word++;         // 일반 알파벳 "c"인 경우
        }
        else if(str[i] == 'd'){
            if(str[i+1] == 'z' && str[i+2] == '='){
                i += 2;
                word++;
            }                   // 크로아티아 문자 "dz="일 경우
            else if(str[i+1] == '-'){
                i++;
                word++;
            }                   // 크로아티아 문자 "d-"일 경우
            else
                word++;
        }                       // 일반 알파벳 "d"인 경우
        else if(str[i] == 'l'){
            if(str[i+1] == 'j'){
                i++;
                word++;
            }                   // 크로아티아 문자 "lj"일 경우
            else
                word++;         // 일반 알파벳 "l"인 경우
        }
        else if(str[i] == 'n'){
            if(str[i+1] == 'j'){
                i++;
                word++;
            }                   // 크로아티아 문자 "nj"일 경우
            else
                word++;         // 일반 알파벳 "n"인 경우
        }
        else if(str[i] == 's'){
            if(str[i+1] == '='){
                i++;
                word++;
            }                   // 크로아티아 문자 "s="일 경우
            else
                word++;         // 일반 알파벳 "s"인 경우
        }
        else if(str[i] == 'z'){
            if(str[i+1] == '='){
                i++;
                word++;
            }                   // 크로아티아 문자 "z="일 경우
            else
                word++;         // 일반 알파벳 "z"인 경우
        }
        else
            word++;             // 일반 알파벳일 경우
    }

    printf("%d\n", word);

    return 0;
}