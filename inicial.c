#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerArquivoCSV(const char* nomeArquivo) {
    FILE *arquivo;
    char *linha = NULL;
    size_t tamanhoLinha = 0;

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
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

    fclose(arquivo);
    free(linha);
}

int main() {
    char nomeArquivo[100];

    printf("Digite o nome do arquivo CSV: ");
    scanf("%s", nomeArquivo);

    lerArquivoCSV(nomeArquivo);

    return 0;
}



