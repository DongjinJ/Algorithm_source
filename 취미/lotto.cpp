#include <iostream>
#include <stdio.h>
#include <cmath>

#define EPSILON 0.0000001

using namespace std;

int combination(int n , int r){
    if(n == r || r == 1)
        return 1;
    else 
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

bool float_compare(float a, float b)
{   

    if((a-b) > EPSILON)
        return true; // �ռ� ������ 0.0000001 ���ϴ� ������ �ʽ��ϴ�.
    else
        return false;
}

int main(){
    FILE *pFile = NULL;

    pFile = fopen("C:\\Users\\Sulja\\OneDrive\\Algorithm_source\\���\\lotto.txt", "r");

    int lotto[45] = {0, };
    int total = 0;

   

    if(pFile == NULL){
        cout << "���� �ҷ����� ����" << endl;
        return -1;
    }
    else{
        int temp;
        while( !feof(pFile)){
            for(int i = 0;i < 6;i++){
                fscanf(pFile, "%d\t", &temp);
                lotto[temp - 1]++;
                total++;
            }
            fscanf(pFile, "%d\n", &temp);
            lotto[temp - 1]++;
            total++; 
        }
        fclose(pFile);
    }
    
    float real_probabilty = (float)combination(44, 5) / (float)combination(45, 6);
    int total_outcomes = combination(45, 6);
    int sub_outcomes = combination(44, 5);

    cout << "��ü ����� ��: " << total_outcomes << endl; 
    cout << "�κ� ����� ��: " << sub_outcomes << endl;
    cout << "��ȣ �� ���� Ȯ��: " << real_probabilty << endl;


    cout << "total: " << total << endl;

    float probability[45] = {0.0, };
    for(int i = 0;i < 45;i++){
        probability[i] = real_probabilty - (float)lotto[i] / (float)total;
    }
    

    cout << "���ɼ� ���� ��ȣ" << endl;
    for(int i = 0;i < 45;i++){
        int rank = 1;
        for(int j = 0;j < 45;j++){
            if(float_compare(probability[j], probability[i]))
                rank++;
        }
        if(rank <= 6)
            printf("%d(%d)\t", i + 1, rank);
        
    }
    cout << endl;
 
    for(int i = 0;i <45;i++){
        cout << probability[i] << "\t";
        if((i+1) % 5 == 0)
            cout << endl;
    }
    cout << endl;

    system("pause");
    
    return 0;
}