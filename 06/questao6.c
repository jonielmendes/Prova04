#include <stdio.h>
#include <ctype.h>
int tam(char *palavra){ 
    int tamanho=0;
    for(int i=0;palavra[i]!='\0';i++)
        tamanho++;
    return tamanho;
}
void criptografar(char *palavra,char *chave){ 
    char palavraCriptografada[27];
    int i;
    for( i=0;palavra[i]!='\0';i++){
        if(isupper(palavra[i])){
            palavraCriptografada[i] = toupper(chave[palavra[i]-'A']);
        }else if(islower(palavra[i])){
            palavraCriptografada[i] = tolower(chave[palavra[i]-'a']);
        }else{
            palavraCriptografada[i] = palavra[i];
        }
    }
    palavraCriptografada[i]='\0'; 
    printf("\nPalavra normal:        %s",palavra);
    printf("\nPalavra criptografada: %s",palavraCriptografada);
}
int main(){
    char chave[27];
    char palavra[27];
    while(1){
        printf("\nChave de criptografia (26 digitos):");
        scanf("%26s",chave);
        if(tam(chave)!=26)
            printf("\nA chave de criptografia informada não contém 26 digitos\n");
        else{
            printf("\nInforma a palavra que deseja criptografar:");
            scanf("%26s",palavra);
            criptografar(palavra,chave);
            break;
        }
        
    }
    return 0;
}