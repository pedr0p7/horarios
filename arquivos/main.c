
#include "arvores.h"

#define MAX_NAMEFILE_LENGTH 250

int main() {

    setlocale(LC_ALL, "UTF-8");

    char nomeArquivo [MAX_NAMEFILE_LENGTH];
    printf("\n------------------------------------------------------------------------------------------------------------\n");
    printf("Detectar Colisões de Horários");
    printf("\n------------------------------------------------------------------------------------------------------------\n");
    printf("Digite o caminho do arquivo a ser lido: ");
    scanf("%s", nomeArquivo);

    printf("\n------------------------------------------------------------------------------------------------------------\n");
    printf("Iniciando leitura...");
    printf("\n------------------------------------------------------------------------------------------------------------\n");
    Node* root = leituraArquivoeGerarArvore(nomeArquivo);

    if(root != NULL){
        char arquivoSaida [MAX_NAMEFILE_LENGTH];
        printf("\n------------------------------------------------------------------------------------------------------------\n");
        printf("Digite o nome do arquivo de saída com o final .txt ou .csv: ");
        scanf("%s", arquivoSaida);

        printf("\n------------------------------------------------------------------------------------------------------------\n");
        printf("Árvore n-ária impressa:");
        printf("\n------------------------------------------------------------------------------------------------------------\n");

        printTree(root, 0);

        printf("\n------------------------------------------------------------------------------------------------------------\n");
        printf("Verificando colisões...");
        printf("\n------------------------------------------------------------------------------------------------------------\n");


        checkColissions(root);
        infoSaida* list = runTree(root);
        createList (root, 5, &list);
        freeTree(root);
        quickSort(&list);
        gerarArquivoSaida(nomeArquivo, arquivoSaida, list);
        freeList(list);

        printf("\n------------------------------------------------------------------------------------------------------------\n");
        printf("Arquivo de saída gerado %s", arquivoSaida);
        printf("\n------------------------------------------------------------------------------------------------------------\n");
    }

    printf("\n------------------------------------------------------------------------------------------------------------\n");
    printf("FIM!");
    printf("\n------------------------------------------------------------------------------------------------------------\n");


    return 0;
}

