#include <iostream>

#define MAX 1000001
using namespace std;

int heap[MAX];
int n;

void heapify(int i){
    int cur = i * 2;

    if(cur < n && heap[cur] < heap[cur + 1])
        cur++;
    
    if(heap[i] < heap[cur]){
        swap(heap[i], heap[cur]);
        if(cur <= n/2) heapify(cur);
    }
}

void heapsort(int i){
    swap(heap[1], heap[i]);

    int root = 1;
    int cur = 2;

    while(cur / 2 < i){
        cur = 2 * root;
        if(cur < i - 1 && heap[cur] < heap[cur+1]) 
            cur++;
        if(cur < i && heap[root] < heap[cur])
            swap(heap[root], heap[cur]);
        
        root = cur;
    }
}
int main(){
    scanf("%d", &n);

    for(int i = 1;i <= n;i++)
        scanf("%d", &heap[i]);

    for(int i = n/2;i > 0;i--)
        heapify(i);

    for(int i = n;i > 0;i--)
        heapsort(i);

    for(int i = 1;i <= n;i++)
        printf("%d\n", heap[i]);

    return 0;
}