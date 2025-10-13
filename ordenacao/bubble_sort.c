#include <stdio.h>

void bubble_sort(int v[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                // Troca os elementos
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        } 
    }
}

int main() {
    int v[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Antes da ordenacao: ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    bubble_sort(v, n);

    printf("Depois da ordenacao: ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}
