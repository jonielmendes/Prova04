#include <stdio.h>
#include <ctype.h>

void criptografar(int chave, char *palavraSimples, char *palavraCifrada) {
    int i;
    for (i = 0; palavraSimples[i] != '\0'; i++) {
        if (palavraSimples[i] == '\n') {
            palavraSimples[i] = '\0';
            break;
        }
        if (isupper(palavraSimples[i])) { 
            palavraCifrada[i] = (((palavraSimples[i] - 'A' + chave) % 26) + 'A');
        } else if (islower(palavraSimples[i])) { 
            palavraCifrada[i] = (((palavraSimples[i] - 'a' + chave) % 26) + 'a');
        } else { 
            palavraCifrada[i] = palavraSimples[i];
        }
    }
    palavraCifrada[i] = '\0'; 
    printf("\nPalavra Simples: %s", palavraSimples);
    printf("\nPalavra Cifrada: %s", palavraCifrada);
}

int main() {
    int chave;
    char palavraSimples[27];
    char palavraCifrada[27];
    
    while (1) {
        printf("\nDigite a chave de criptografia: ");
        if (scanf("%d", &chave) != 1) {
            printf("Chave inválida. Por favor, insira um número.\n");
            while (getchar() != '\n'); 
            continue;
        }

        
        while (getchar() != '\n');

        printf("Digite a palavra que deseja criptografar: ");
        fgets(palavraSimples, sizeof(palavraSimples), stdin);
        if (palavraSimples[0] == '\n') {
            printf("Erro ao ler a entrada.\n");
            continue;
        }

        criptografar(chave, palavraSimples, palavraCifrada);
    }

    return 0;
}
