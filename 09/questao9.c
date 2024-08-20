#include <stdio.h>
#include <string.h>

#define PEDRA 0
#define PAPEL 1
#define TESOURA 2
#define LAGARTO 3
#define SPOCK 4

int resultado[5][5] = {
    {0,       2,     1,       1,       2},  
    {1,       0,     2,       2,       1},  
    {2,       1,     0,       1,       2},  
    {2,       1,     2,       0,       1},  
    {1,       2,     1,       2,       0}   
};


int escolha_para_indice(char* escolha) {
    if (strcmp(escolha, "pedra") == 0) return PEDRA;
    if (strcmp(escolha, "papel") == 0) return PAPEL;
    if (strcmp(escolha, "tesoura") == 0) return TESOURA;
    if (strcmp(escolha, "lagarto") == 0) return LAGARTO;
    if (strcmp(escolha, "Spock") == 0) return SPOCK;
    return -1; 
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        char escolha_sheldon[10], escolha_raj[10];
        scanf("%s %s", escolha_sheldon, escolha_raj);
        int indice_sheldon = escolha_para_indice(escolha_sheldon);
        int indice_raj = escolha_para_indice(escolha_raj);
        if (indice_sheldon == -1 || indice_raj == -1) {
            printf("Caso #%d: Entrada inválida\n", t);
            continue;
        }
        int resultado_jogo = resultado[indice_sheldon][indice_raj];
        if (resultado_jogo == 0) {
            printf("Caso #%d: De novo!\n", t);
        } else if (resultado_jogo == 1) {
            printf("Caso #%d: Bazinga!\n", t);
        } else {
            printf("Caso #%d: Raj trapaceou!\n", t);
        }
    }

    return 0;
}
