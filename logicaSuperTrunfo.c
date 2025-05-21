#include <stdio.h>

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

void calcularDados(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadePopulacional;
        default: return 0.0;
    }
}

void exibirNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
    }
}

int main() {
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 2300.5, 80};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1200.3, 900.7, 60};

    calcularDados(&carta1);
    calcularDados(&carta2);

    int op1, op2;

    printf("=== MENU DE ESCOLHA DE ATRIBUTOS ===\n");
    printf("Escolha o PRIMEIRO atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("Digite a opção: ");
    scanf("%d", &op1);

    // Validação da primeira escolha
    while (op1 < 1 || op1 > 5) {
        printf("Opção inválida! Escolha entre 1 e 5: ");
        scanf("%d", &op1);
    }

    printf("\nEscolha o SEGUNDO atributo para comparação (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != op1) {
            printf("%d - ", i);
            exibirNomeAtributo(i);
            printf("\n");
        }
    }
    printf("Digite a opção: ");
    scanf("%d", &op2);

    // Validação da segunda escolha
    while (op2 == op1 || op2 < 1 || op2 > 5) {
        printf("Opção inválida ou repetida! Escolha outro atributo: ");
        scanf("%d", &op2);
    }

    float valor1_attr1 = obterValorAtributo(carta1, op1);
    float valor2_attr1 = obterValorAtributo(carta2, op1);
    float valor1_attr2 = obterValorAtributo(carta1, op2);
    float valor2_attr2 = obterValorAtributo(carta2, op2);

    int pontos1 = 0, pontos2 = 0;

    // Comparação primeiro atributo
    if (op1 == 5) { // Densidade - menor vence
        if (valor1_attr1 < valor2_attr1) pontos1++;
        else if (valor2_attr1 < valor1_attr1) pontos2++;
    } else {
        if (valor1_attr1 > valor2_attr1) pontos1++;
        else if (valor2_attr1 > valor1_attr1) pontos2++;
    }

    // Comparação segundo atributo
    if (op2 == 5) { // Densidade - menor vence
        if (valor1_attr2 < valor2_attr2) pontos1++;
        else if (valor2_attr2 < valor1_attr2) pontos2++;
    } else {
        if (valor1_attr2 > valor2_attr2) pontos1++;
        else if (valor2_attr2 > valor1_attr2) pontos2++;
    }

    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Cidades: %s (Carta 1) x %s (Carta 2)\n", carta1.nomeCidade, carta2.nomeCidade);

    printf("\nAtributo 1: ");
    exibirNomeAtributo(op1);
    printf("\n- %s: %.2f\n- %s: %.2f\n", carta1.nomeCidade, valor1_attr1, carta2.nomeCidade, valor2_attr1);

    printf("\nAtributo 2: ");
    exibirNomeAtributo(op2);
    printf("\n- %s: %.2f\n- %s: %.2f\n", carta1.nomeCidade, valor1_attr2, carta2.nomeCidade, valor2_attr2);

    printf("\nSoma dos dois atributos:\n");
    printf("- %s: %.2f\n", carta1.nomeCidade, soma1);
    printf("- %s: %.2f\n", carta2.nomeCidade, soma2);

    printf("\nResultado final: ");
    if (soma1 > soma2) {
        printf("Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (soma2 > soma1) {
        printf("Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
