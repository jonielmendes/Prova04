#include <stdio.h>

int soma_array(int array[], int tamanho);

int main() {
    int n;
    printf("Digite o numero de elementos do array: ");
    scanf("%d", &n);

    int array[n];
    printf("Digite %d numeros inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    int resultado = soma_array(array, n);
    printf("Soma dos elementos do array: %d\n", resultado);

    return 0;
}

int soma_array(int array[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma;
}
