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

// Funcao para realizar os calculos e gerenciar a interface do conversor de volume
void calcularVolume() {
    int entradaUnidade, saidaUnidade;
    float valor, resultado;
    char *siglaSaida;

    while (1) {
        limparTela();
        printf("Conversor de Volume\n\n");
        printf("Escolha a unidade de entrada:\n");
        printf("1 - Litro\n");
        printf("2 - Mililitro\n");
        printf("3 - Metros Cubicos\n");
        printf("4 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");
        
        if (scanf("%d", &entradaUnidade) != 1 || entradaUnidade < 1 || entradaUnidade > 4) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        if (entradaUnidade == 4) {
            return; // Voltar ao menu principal
        }

        limparTela();
        printf("Conversor de Volume\n\n");
        printf("Escolha a unidade de saida:\n");
        printf("1 - Litro\n");
        printf("2 - Mililitro\n");
        printf("3 - Metros Cubicos\n");
        printf("4 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");
        
        if (scanf("%d", &saidaUnidade) != 1 || saidaUnidade < 1 || saidaUnidade > 4) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        // Voltar ao menu principal
        if (saidaUnidade == 4) {
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
        if (saidaUnidade == 1) {
            siglaSaida = "L";
        } else if (saidaUnidade == 2) {
            siglaSaida = "ml";
        } else if (saidaUnidade == 3) {
            siglaSaida = "m3";
        }

        // Realiza o calculo com base nas unidades
        if (entradaUnidade == 1) { // Litros
            if (saidaUnidade == 2) {
                resultado = valor * 1000; // Litros -> Mililitros
            } else if (saidaUnidade == 3) {
                resultado = valor / 1000; // Litros -> Metros Cubicos
            }
        } else if (entradaUnidade == 2) { // Mililitros
            if (saidaUnidade == 1) {
                resultado = valor / 1000; // Mililitros -> Litros
            } else if (saidaUnidade == 3) {
                resultado = valor / 1000000; // Mililitros -> Metros Cubicos
            }
        } else if (entradaUnidade == 3) { // Metros Cubicos
            if (saidaUnidade == 1) {
                resultado = valor * 1000; // Metros Cubicos -> Litros
            } else if (saidaUnidade == 2) {
                resultado = valor * 1000000; // Metros Cubicos -> Mililitros
            }
        }

        limparTela();
        printf("Resultado da conversao: %.6f %s\n", resultado, siglaSaida);
        pausarTela();
    }
}
// Função para converter entre minutos e horas
void converterTempo() {
    //Menu da Função
    int opcao, minutos, horas, minutosRestantes, totalMinutos;
    limparBuffer();
    limparTela();
    printf("Escolha o tipo de conversao:\n");
    printf("1 - Converter minutos para horas\n");
    printf("2 - Converter horas para minutos\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    limparTela();
   
    if (opcao == 1) {     // Calculo da conversão de Minutos para Horas
        printf("Digite o numero de minutos: ");
        scanf("%d", &minutos);
        horas = minutos / 60;
        minutosRestantes = minutos % 60;
        limparTela();
        printf("%d minutos equivalem a %d horas e %d minutos.\n", minutos, horas, minutosRestantes);
        pausarTela();
    } else if (opcao == 2) {   // Calculo da conversão de Horas para Minutos
        printf("Digite o numero de horas: ");
        scanf("%d", &horas);
        printf("Digite o número de minutos: ");
        scanf("%d", &minutos);
        totalMinutos = (horas * 60) + minutos;
        limparTela();
        printf("%d horas e %d minutos equivalem a %d minutos.\n", horas, minutos, totalMinutos);
        pausarTela();
    } else {
        limparTela();
        printf("Opcao invalida.\n");
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
        printf("8 - Converter Horas e Minutos\n");
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
            case 8:
                 converterTempo();
                break;
            case 10:
                limparTela();
                printf("Finalizando o conversor...\n");
                return 0;
            default:
                printf("Por favor, escolha uma opcao existente no menu.\n");
                pausarTela();
        }
    }

    return 0;
}
