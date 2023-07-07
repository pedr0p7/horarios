#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void lerArquivoCSV(const char* nomeArquivo) {
    FILE *arquivo;
    char *linha = NULL;
    size_t tamanhoLinha = 0;

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado.\n");
        return;
    }

    while (getline(&linha, &tamanhoLinha, arquivo) != -1) {
        char *campo = strtok(linha, ",");
        while (campo != NULL) {
            printf("%s ", campo);
            campo = strtok(NULL, ",");
        }
        printf("\n");
    }

    free(linha);
    fclose(arquivo);
}

int main() {
    char nomeArquivo[100];

    printf("Digite o nome do arquivo CSV: ");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);

    // Remover o caractere de nova linha '\n' lido pelo fgets
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    lerArquivoCSV(nomeArquivo);

    return 0;
}


