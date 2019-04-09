#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;
int N; 
void quicksort(int *arr, int start, int end){
    if(start >= end)
        return;

    int pivot = start;
    int i = start + 1;
    int j = end;

    while(i <= j){
        while(i <= end && arr[i] <= arr[pivot])
            i++;
        while(j > start && arr[j] >= arr[pivot])
            j--;
        
        if(i > j){
            int temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }
        else{ 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    quicksort(arr, start, j - 1);
    quicksort(arr, j + 1, end);
}
int main(){

    scanf("%d", &N);

    int *data = new int[N];
    int count[8001];
    memset(count, 0, sizeof(count));

    int average = 0;

    int max = 0;

    for(int i = 0;i < N;i++){
        scanf("%d", &data[i]);
        count[data[i] + 4000]++;
        average += data[i];
        if(count[data[i] + 4000] > max){
            max = count[data[i] + 4000];
        }
    }
    
    int min;
    bool second = false;

    for(int i = 0;i < 8001;i++){
        if(count[i] == max){
            if(second){
                min = i - 4000;
                break;
            }
            else{
                min = i - 4000;
                second = true;
            }
        }
        
    }
    
    average = (int)round((double)average / (double)N);
    quicksort(data, 0, N-1);

    printf("%d\n%d\n%d\n%d\n", average, data[N/2], min, data[N-1] - data[0]);

    delete []data;

    return 0;
}