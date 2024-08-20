#include <stdio.h>

int main(void)
{
    int cents;
    printf("Troco devido (em centavos): ");
    scanf("%d", &cents);

    
    while (cents < 0)
    {
        printf("O valor deve ser um numero nao negativo.\n");
        printf("Troco devido (em centavos): ");
        scanf("%d", &cents);
    }
    int coins = 0;
    coins += cents / 25;
    cents %= 25;
    coins += cents / 10;
    cents %= 10;
    coins += cents / 5;
    cents %= 5;
    coins += cents;
    printf("Numero minimo de moedas: %d\n", coins);

    return 0;
}
