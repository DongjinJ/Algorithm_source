#include <iostream>

using namespace std;

void quick_sort(int* arr, int start, int end){
    if(start >= end)
        return ;
    
    int pivot = start;                                      // ���� ù��° ���Ҹ� pivot���� ����
    int i  = pivot + 1;                                     // pivot ���� ������ i
    int j = end;                                            // ������ ���Ҹ� j
    int temp;

    while(i <= j){
        while(i <= end && arr[i] <= arr[pivot])             // pivot�� ����Ű�� ���Һ��� ū ���� ã��
            i++;    
        while(j > start && arr[j] >= arr[pivot])            // pivot�� ����Ű�� ���Һ��� ���� ���� ã��
            j--;
        
        if(i > j){
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }                                                   // i�� j�� �������� ��� j�� pivot�� ����Ű�� ���� �ٲ�
        else{
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }                                                   // i�� j�� �������� �ʾ��� ��� i�� j�� ����Ű�� ���� �ٲ�
    }
    
    quick_sort(arr, start, j);                              // ���ĵ� j�� �������� j������ ������ �ٽ� ����
    quick_sort(arr, j + 1, end);                            // ���ĵ� j�� �������� j������ ������ �ٽ� ����
}
int main(){
    int N;
    scanf("%d", &N);

    int* arr = new int[N];

    for(int i = 0;i < N;i++)
        scanf("%d", &arr[i]);
    
    quick_sort(arr, 0, N - 1);

    for(int i = 0;i < N;i++)
        printf("%d\n", arr[i]);

    delete []arr;
    
    return 0;
}