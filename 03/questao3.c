#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>

#define MAX_DIGITS 19  // Tamanho máximo do número de cartão de crédito

// Função que calcular a soma dos dígitos usando o Algoritmo de Luhn
int calcular_soma(const char* numero) {
    int soma_nao_multiplicado = 0;
    int soma_multiplicado = 0;
    int len = strlen(numero);
    
    for (int i = len - 1; i >= 0; i--) {
        int digito = numero[i] - '0';
        if ((len - i) % 2 == 0) { 
            int multiplicado = digito * 2;
            soma_multiplicado += (multiplicado > 9) ? (multiplicado - 9) : multiplicado;
        } else { 
            soma_nao_multiplicado += digito;
        }
    }
    return soma_nao_multiplicado + soma_multiplicado;
}

// Função para identificar o tipo do cartão
const char* identificar_tipo_cartao(const char* numero) {
    int len = strlen(numero);
    int prefixo = 0;

    if (len >= 2) {
        prefixo = (numero[0] - '0') * 10 + (numero[1] - '0');
    }

    if (prefixo == 34 || prefixo == 37) {
        return "AMEX";
    } else if (prefixo >= 51 && prefixo <= 55) {
        return "MASTERCARD";
    } else if (prefixo >= 40 && prefixo <= 49) {
        return "VISA";
    } else {
        return "INVALID";
    }
}

// Função para limpar a entrada removendo caracteres não numéricos
void limpar_entrada(const char* entrada, char* numero) {
    int j = 0;
    for (int i = 0; i < strlen(entrada); i++) {
        if (isdigit(entrada[i])) {
            numero[j++] = entrada[i];
        }
    }
    numero[j] = '\0';  
}

int main() {
    char entrada[MAX_DIGITS + 1];  
    char numero[MAX_DIGITS + 1];  

    printf("Number: ");
    if (fgets(entrada, sizeof(entrada), stdin) != NULL) {
        entrada[strcspn(entrada, "\n")] = '\0';

        limpar_entrada(entrada, numero);

        int len = strlen(numero);
        if (len >= 13 && len <= 19) {
            // Verifica a validade do cartão
            int soma = calcular_soma(numero);
            if (soma % 10 == 0) {
                printf("%s\n", identificar_tipo_cartao(numero));
            } else {
                printf("INVALID\n");
            }
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }

    return 0;
}

   