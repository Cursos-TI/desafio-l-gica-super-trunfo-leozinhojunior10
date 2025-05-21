#include <stdio.h>

// Estrutura da carta
typedef struct {
    char estado[50];
    char codigo[20];
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular dados derivados
void calcularDados(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

// Função para exibir dados da carta
void imprimirCarta(Carta c) {
    printf("Cidade: %s (%s)\n", c.nomeCidade, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2f\n", c.pibPerCapita);
    printf("-------------------------------\n");
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 2300.5, 80};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1200.3, 900.7, 60};

    // Cálculo dos dados derivados
    calcularDados(&carta1);
    calcularDados(&carta2);

    int opcao;

    printf("===== Cartas Super Trunfo =====\n");
    imprimirCarta(carta1);
    imprimirCarta(carta2);

    printf("\n===== MENU DE COMPARAÇÃO =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\n=== Comparação de cartas ===\n");

    switch (opcao) {
        case 1: // População
            printf("População:\n");
            printf("%s: %d\n", carta1.nomeCidade, carta1.populacao);
            printf("%s: %d\n", carta2.nomeCidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.populacao > carta1.populacao)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2: // Área
            printf("Área:\n");
            printf("%s: %.2f km²\n", carta1.nomeCidade, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomeCidade, carta2.area);
            if (carta1.area > carta2.area)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.area > carta1.area)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3: // PIB
            printf("PIB:\n");
            printf("%s: %.2f bilhões\n", carta1.nomeCidade, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.nomeCidade, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.pib > carta1.pib)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Pontos Turísticos:\n");
            printf("%s: %d\n", carta1.nomeCidade, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.nomeCidade, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5: // Densidade Demográfica (MENOR vence)
            printf("Densidade Demográfica:\n");
            printf("%s: %.2f hab/km²\n", carta1.nomeCidade, carta1.densidadePopulacional);
            printf("%s: %.2f hab/km²\n", carta2.nomeCidade, carta2.densidadePopulacional);
            if (carta1.densidadePopulacional < carta2.densidadePopulacional)
                printf("Resultado: %s venceu!\n", carta1.nomeCidade);
            else if (carta2.densidadePopulacional < carta1.densidadePopulacional)
                printf("Resultado: %s venceu!\n", carta2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }

    return 0;
}
