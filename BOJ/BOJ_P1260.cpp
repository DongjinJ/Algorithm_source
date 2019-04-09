#include <iostream>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;

int node[1001][1001];
bool check[1001];

void DFS(int root){
    check[root] = true;
    printf("%d ", root);
}
void BFS(int root){

}
int main(){
    int N_max, M_max, start;
    scanf("%d %d %d", &N_max, &M_max, &start);
    memset(node, -1, sizeof(node));

    for(int i = 0;i < M_max;i++){
        int p, c;
        scanf("%d %d", &p, &c);
        node[p][c] = 1;
        node[c][p] = 1;
    }

    memset(check, false, sizeof(check));
    DFS(start);

    memset(check, false, sizeof(check));
    BFS(start);

    return 0;
}