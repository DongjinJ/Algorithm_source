#include <iostream>

using namespace std;

void quick_sort(int* arr, int start, int end){
    if(start >= end)
        return ;
    
    int pivot = start;                                      // 가장 첫번째 원소를 pivot으로 설정
    int i  = pivot + 1;                                     // pivot 다음 수부터 i
    int j = end;                                            // 마지막 원소를 j
    int temp;

    while(i <= j){
        while(i <= end && arr[i] <= arr[pivot])             // pivot이 가리키는 원소보다 큰 값을 찾음
            i++;    
        while(j > start && arr[j] >= arr[pivot])            // pivot이 가리키는 원소보다 작은 값을 찾음
            j--;
        
        if(i > j){
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }                                                   // i와 j가 교차햇을 경우 j와 pivot이 가리키는 값을 바꿈
        else{
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }                                                   // i와 j가 교차하지 않았을 경우 i와 j가 가리키는 값을 바꿈
    }
    
    quick_sort(arr, start, j);                              // 정렬된 j를 기준으로 j앞쪽을 분할해 다시 정렬
    quick_sort(arr, j + 1, end);                            // 정렬된 j를 기준으로 j뒤쪽을 분할해 다시 정렬
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