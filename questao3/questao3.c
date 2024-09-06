#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIAS_NO_ANO 252 // Considerando apenas dias úteis no ano

// Função para encontrar o maior e o menor valor em um vetor
void encontra_maior_e_menor_valor(int *vet, int *maior, int *menor) {
    *maior = vet[0]; // Inicializa o maior valor com o primeiro elemento
    *menor = vet[0]; // Inicializa o menor valor com o primeiro elemento

    for (int i = 1; i < DIAS_NO_ANO; i++) { // Percorre o vetor a partir do segundo elemento
        if (vet[i] > *maior) { // Se o elemento atual é maior que o maior valor encontrado
            *maior = vet[i]; // Atualiza o maior valor
        }
        if (vet[i] < *menor) { // Se o elemento atual é menor que o menor valor encontrado
            *menor = vet[i]; // Atualiza o menor valor
        }
    }
}

// Função para calcular a média dos valores em um vetor
double calcula_media_anual(int *vet) {
    double soma = 0; // Variável para armazenar a soma dos valores
    for (int i = 0; i < DIAS_NO_ANO; i++) {
        soma += vet[i]; // Acumula a soma dos valores
    }
    return soma / DIAS_NO_ANO; // Retorna a média dos valores
}

// Função para contar quantos dias têm valores acima da média
int conta_dias_acima_da_media(int *vet, double media) {
    int contagem = 0; // Variável para armazenar a contagem de dias acima da média
    for (int i = 0; i < DIAS_NO_ANO; i++) {
        if (vet[i] > media) { // Se o valor do dia é maior que a média
            contagem++; // Incrementa a contagem
        }
    }
    return contagem; // Retorna o número de dias acima da média
}

int main() {
    int vet[DIAS_NO_ANO]; // Vetor para armazenar os valores dos dias
    int maior_valor, menor_valor, dias_acima_da_media;
    double media_anual;

    srand(time(NULL)); // Inicializa o gerador de números aleatórios com o tempo atual
    for (int i = 0; i < DIAS_NO_ANO; i++) {
        vet[i] = rand() % 1000000000; // Preenche o vetor com valores aleatórios
    } // Assumo que o faturamento diário nunca será maior que 1000000000

    encontra_maior_e_menor_valor(vet, &maior_valor, &menor_valor); // Encontra o maior e menor valor
    printf("Maior valor: %d\nMenor valor: %d\n", maior_valor, menor_valor); // Imprime o maior e menor valor

    media_anual = calcula_media_anual(vet); // Calcula a média anual
    dias_acima_da_media = conta_dias_acima_da_media(vet, media_anual); // Conta os dias com valores acima da média

    printf("Número de dias com faturamento superior à média anual: %d\n", dias_acima_da_media); // Imprime o número de dias acima da média

    return 0; // Finaliza o programa
}
