#include <stdio.h>
void selection_sort(int v[], int n) {
    int temp, menor, i, j;
    
    for (i = 0; i < n; i++){
        menor = i;
        for (j = i + 1; j < n; j++){
            if (v[j] < v[menor]){
                menor = j;
            }
        }

        temp = v[i];
        v[i] = v[menor];
        v[menor] = temp;
        
    }
}



int main(){
    int v[] = {3,2,6,3,7,8,1,3,10};
    int  n = sizeof(v) / sizeof(v[0]);

    selection_sort(v,n);

    printf("\n\nVetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

}