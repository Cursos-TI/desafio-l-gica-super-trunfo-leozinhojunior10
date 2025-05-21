#include <stdio.h>

// Estrutura para representar uma carta
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

// Função para calcular densidade populacional e PIB per capita
void calcularDados(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

// Função para imprimir dados básicos da carta
void imprimirCarta(Carta c) {
    printf("Cidade: %s (%s)\n", c.nomeCidade, c.estado);
    printf("Código da carta: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2f\n", c.pibPerCapita);
    printf("----------------------------------\n");
}

int main() {
    // Cadastro das cartas (valores fixos)
    Carta carta1 = {
        "SP", "C001", "São Paulo", 12300000, 1521.11, 2300.5, 80
    };

    Carta carta2 = {
        "RJ", "C002", "Rio de Janeiro", 6000000, 1200.3, 900.7, 60
    };

    // Cálculo de dados adicionais
    calcularDados(&carta1);
    calcularDados(&carta2);

    // Impressão das cartas
    printf("=== Cartas Cadastradas ===\n");
    imprimirCarta(carta1);
    imprimirCarta(carta2);

    // Atributo para comparação: População
    printf("Compar
