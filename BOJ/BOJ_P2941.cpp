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
            }
            else if(str[i+1] == '-'){
                i++;
                word++;
            }
            else
                word++;
        }
        else if(str[i] == 'd'){
            if(str[i+1] == 'z' && str[i+2] == '='){
                i += 2;
                word++;
            }
            else if(str[i+1] == '-'){
                i++;
                word++;
            }
            else
                word++;
        }
        else if(str[i] == 'l'){
            if(str[i+1] == 'j'){
                i++;
                word++;
            }
            else
                word++;
        }
        else if(str[i] == 'n'){
            if(str[i+1] == 'j'){
                i++;
                word++;
            }
            else
                word++;
        }
        else if(str[i] == 's'){
            if(str[i+1] == '='){
                i++;
                word++;
            }
            else
                word++;
        }
        else if(str[i] == 'z'){
            if(str[i+1] == '='){
                i++;
                word++;
            }
            else
                word++;        
        }
        else
            word++;
    }

    printf("%d\n", word);

    return 0;
}