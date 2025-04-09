#include <stdio.h>

#define TAMANHO_TABULEIRO 10 //O tabuleiro vai ser 10x10
#define TAMANHO_NAVIO 3 //O navio tem tamanho 3
#define NAVIO 3 //Onde tiver 3 na matriz, é um navio
#define AGUA 0 //Onde tiver 0, é água

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; //Antes de colocar o navio, o mar está vazio

    // Coordenadas iniciais dos navios

    int linhaNavioVertical = 2;
    int colunaNavioVertical = 3;

    int linhaNavioHorizontal = 4;
    int colunaNavioHorizontal = 5;

    int i;
    int sobreposicao = 0;

    // Validação: se navio vertical cabe

    if (linhaNavioVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Navio vertical fora dos limites! \n");
        return 1;
    }

    // Validação: se navio horizontal cabe

    if (colunaNavioHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Navio horizontal fora dos limites! \n");
        return 1;
    }

    // Verificar sobreposição antes de posicionar

    for (i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] == NAVIO ||
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] == NAVIO) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: os navios se sobrepõem!\n");
        return 1;
    }

    // Posiciona navio vertical

    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = NAVIO;
    }

    // Posiciona navio horizontal

    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = NAVIO;
    }

    // Exibe o tabuleiro

    printf("Tabuleiro: \n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}