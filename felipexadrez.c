#include <stdio.h>

// Função recursiva para movimentar a Torre para a direita
void moverTorre(int casas_restantes) {
    if (casas_restantes <= 0) return;  // Caso base: nenhuma casa para mover

    printf("Direita\n");               // Movimento atual
    moverTorre(casas_restantes - 1);  // Chamada recursiva para próxima casa
}

// Função recursiva para movimentar a Rainha para a esquerda
void moverRainha(int casas_restantes) {
    if (casas_restantes <= 0) return;

    printf("Esquerda\n");
    moverRainha(casas_restantes - 1);
}

// Função recursiva para movimentar o Bispo na diagonal cima-direita usando loops aninhados
// Vertical (cima) - loop externo, Horizontal (direita) - loop interno
void moverBispoRecursivo(int casas_restantes) {
    if (casas_restantes <= 0) return;

    // Loop aninhado: para representar diagonal "cima + direita"
    for (int i = 0; i < 1; i++) {       // Loop vertical (cima) - sempre 1 neste caso
        for (int j = 0; j < 1; j++) {   // Loop horizontal (direita) - sempre 1
            printf("Cima, Direita\n");
        }
    }

    moverBispoRecursivo(casas_restantes - 1);
}

// Função para movimentar o Cavalo usando loops aninhados complexos
// Movimento: 2 casas para cima e 1 para a direita (em L)
// Usaremos variáveis para controlar os movimentos e condições para 'break' e 'continue'
void moverCavalo() {
    printf("Movimento do Cavalo (2 casas para cima e 1 casa para a direita):\n");

    int movimentosL = 1;  // Quantos movimentos em L queremos simular
    int l_move = 0;

    while (l_move < movimentosL) {
        int passosCima = 0;

        for (;;) {  // Loop infinito controlado por break, simulando movimento para cima
            if (passosCima >= 2) {
                // Após 2 passos para cima, sai do loop
                break;
            }

            printf("Cima\n");
            passosCima++;

            // Exemplo de uso do continue: só para mostrar como funciona
            if (passosCima < 2) {
                continue;  // Continua o loop até 2 passos
            }
        }

        // Depois de subir 2 casas, mover 1 casa para a direita
        printf("Direita\n");

        l_move++;
    }
}

int main() {
    // Definição das casas a mover para cada peça
    const int casasTorre = 5;
    const int casasBispo = 5;
    const int casasRainha = 8;

    // Torre - movimento recursivo para a direita
    printf("Movimento da Torre (5 casas para a direita):\n");
    moverTorre(casasTorre);
    printf("\n");

    // Bispo - movimento recursivo com loops aninhados para cima-direita
    printf("Movimento do Bispo (5 casas na diagonal cima-direita):\n");
    moverBispoRecursivo(casasBispo);
    printf("\n");

    // Rainha - movimento recursivo para a esquerda
    printf("Movimento da Rainha (8 casas para a esquerda):\n");
    moverRainha(casasRainha);
    printf("\n");

     // Cavalo - movimento complexo com loops aninhados, break e continue
    moverCavalo();

    return 0;
}