#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#include "resource.h"
#include "galho.h"

// Variáveis globais
HWND h_caixa1, h_caixa2, h_caixa3;

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG: {

        // Caixa do caminho
        h_caixa1 = GetDlgItem(hwndDlg, C1);
        // Caixa de sáida
        h_caixa2 = GetDlgItem(hwndDlg, C2);
        // Caixa de impressão
        h_caixa3 = GetDlgItem(hwndDlg, C3);
    }
    return TRUE;

    case WM_CLOSE: {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND: {
    switch (LOWORD(wParam)) {
    case Gerar: {
        // Obter o caminho do arquivo da caixa de texto
        char arquivo[MAX_PATH];
        char arquivoSaida[MAX_PATH];
        GetWindowText(h_caixa1, arquivo, MAX_PATH);

        // Ler o arquivo e gerar a árvore
        Node* root = leituraArquivoeGerarArvore(arquivo);
        SendMessage(h_caixa3, EM_REPLACESEL, FALSE, (LPARAM)"Leitura do arquivo concluida.\r\n");

        GetWindowText(h_caixa2, arquivoSaida, MAX_PATH);
        SendMessage(h_caixa3, EM_SETSEL, -1, -1); // Define o cursor no final
        SendMessage(h_caixa3, EM_REPLACESEL, FALSE, (LPARAM)"Arvore gerada com sucesso.\r\n");

        // Imprimir a árvore
        printTree(root, 0);

        checkColissions(root);
        SendMessage(h_caixa3, EM_SETSEL, -1, -1); // Define o cursor no final
        SendMessage(h_caixa3, EM_REPLACESEL, FALSE, (LPARAM)"Procurando colisoes...\r\n");

        SendMessage(h_caixa3, EM_SETSEL, -1, -1); // Define o cursor no final
        SendMessage(h_caixa3, EM_REPLACESEL, FALSE, (LPARAM)"Arquivo de saida criado com sucesso.\r\n");

        infoSaida* list = runTree(root);
        createList(root, 5, &list);

        freeTree(root);
        SendMessage(h_caixa3, EM_SETSEL, -1, -1); // Define o cursor no final
        SendMessage(h_caixa3, EM_REPLACESEL, FALSE, (LPARAM)"Liberando memoria ...\r\n");

        quickSort(&list);

        gerarArquivoSaida(arquivo, arquivoSaida, list);
        SendMessage(h_caixa3, EM_SETSEL, -1, -1); // Define o cursor no final
        SendMessage(h_caixa3, EM_REPLACESEL, FALSE, (LPARAM)"Arquivo de saida gerado com sucesso.\r\n");

        freeList(list);
        SendMessage(h_caixa3, EM_SETSEL, -1, -1); // Define o cursor no final
        SendMessage(h_caixa3, EM_REPLACESEL, FALSE, (LPARAM)"Liberando memoria da lista ...\r\n");

        SendMessage(h_caixa3, EM_SETSEL, -1, -1); // Define o cursor no final
        SendMessage(h_caixa3, EM_REPLACESEL, FALSE, (LPARAM)"----Fim---\r\n");
    }
    break;
    }
}

break;


    return TRUE;
    }
    return FALSE;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    InitCommonControls();
    return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
