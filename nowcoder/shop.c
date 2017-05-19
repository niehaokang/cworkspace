#include <stdio.h>
#include <stdlib.h>

//从小到大排序，取前面不超过V的n个物品
int comfunc(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int f(int* a, int len, int v){
    int i;
    int sum = 0;
    int n = 0;		//物品件数
    qsort(a, len, sizeof(int), comfunc);
    for(i=0; i<len; i++){
        if(a[i] + sum <= v) {
            sum += a[i];
            n++;
        }
        else
            break;
    }
    return n;
}

int main(){
    int i;
    int n, V;
    int* a;
    
    while(scanf("%d %d", &n, &V) != EOF) {
        a = (int*) malloc(n * sizeof(int));
        for(i=0; i<n; i++)
            scanf("%d", a+i);
        
        printf("%d\n", f(a, n, V));
        free(a);
    }
}	
