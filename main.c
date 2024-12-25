#include <stdio.h>
#include <stdlib.h>

// Funcao para limpar a tela em ambos sistemas operacionais
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Funcao para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Funcao para pausar a tela em ambos sistemas operacionais
void pausarTela() {
    #ifdef _WIN32
        system("pause");
    #else
        printf("Pressione qualquer tecla para continuar...");
        getchar();
    #endif
}



// Funcao para realizar os calculos e gerenciar a interface do conversor de unidades de area
void calcularArea() {
    int entradaarea, saidaarea;
    float valor, resultado;
    char *siglaSaida;

    while (1) {
        limparTela();
        printf("Conversor de unidade de area\n\n\n");
        printf("Escolha a unidade de entrada:\n");
        printf("1 - metros quadrados\n");
        printf("2 - centimetros quadrados\n");
        printf("3 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");
        
        if (scanf("%d", &entradaarea) != 1 || entradaarea < 1 || entradaarea > 3) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        if (entradaarea == 3) {
            return; // Voltar ao menu principal
        }

        limparTela();
        printf("Conversor de unidade de area\n\n");
        printf("Escolha a unidade de saida:\n");
        printf("1 - metros quadrados\n");
        printf("2 - centimetros quadrados\n");
        printf("3 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");
        
        if (scanf("%d", &saidaarea) != 1 || saidaarea < 1 || saidaarea > 3) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        if (saidaarea == 3) {
            return;
        }

        limparTela();
        printf("Digite o valor a ser convertido (ex: 50.00 ou 50) : ");
        
        if (scanf("%f", &valor) != 1) {
            limparBuffer();
            printf("Por favor, insira um valor no formato do exemplo.\n");
            pausarTela();
            continue;
        }

        // Define a sigla da unidade de saída
        if (saidaarea == 1) {
            siglaSaida = "m2";
        } else if (saidaarea == 2) {
            siglaSaida = "cm2";
        }

        // Realiza o calculo com base nas unidades
        if (entradaarea == 1) { // metros quadrados
            if (saidaarea == 2) {
                resultado = valor * 10000; // metros quadrados -> centimetros quadrados
            } else if (saidaarea == 1) { // metros quadrados -> metros quadrados (sem conversão)
                resultado = valor;
            }
        } else if (entradaarea == 2) { // centimetros quadrados
            if (saidaarea == 1) {
                resultado = valor / 10000; // centimetros quadrados -> metros quadrados
            } else if (saidaarea == 2) { // centimetros quadrados -> centimetros quadrados (sem conversão)
                resultado = valor;
            }
        }

        limparTela();
        printf("Resultado da conversao: %.4f %s\n", resultado, siglaSaida);
        pausarTela();
    }
}

int main() {
    int opcao;

    while (1) {
        limparTela();
        printf("Bem-vindo ao Conversor de Unidades\n\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Converter Volume\n");
        printf("2 - Conversor de Potencia\n");
        printf("3 - Conversor de Area\n");
        printf("10 - Sair\n");
        printf("\nDigite a opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        switch (opcao) {
            case 1:
                calcularVolume();
                break;
            case 2:
                calcularPotencia();
                break;
            case 3:
                calcularArea();
                break;
            case 10:
                limparTela();
                printf("Finalizando o conversor...\n");
                return 0;
            default:
                limparBuffer();
                printf("Por favor, escolha uma opcao existente no menu.\n");
                pausarTela();
        }
    }

    return 0;
}
