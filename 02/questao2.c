#include <stdio.h>

void multiplica_matrizes(int n, int matriz1[n][n], int matriz2[n][n], int resultado[n][n]){
    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            resultado[i][j] = 0;
            int k = 0;
            while (k < n) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
                k++;
            }
            j++;
        }
        i++;
    }

    printf("Matriz Resultante:\n");
    i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            printf("%d ", resultado[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int matriz1[n][n], matriz2[n][n], resultado[n][n];
    
    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            scanf("%d", &matriz1[i][j]);
            j++;
        }
        i++;
    }
    i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            scanf("%d", &matriz2[i][j]);
            j++;
        }
        i++;
    }

    multiplica_matrizes(n, matriz1, matriz2, resultado);
    
    return 0;
}
