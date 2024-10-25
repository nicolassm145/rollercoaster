#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

#define g 10

void shuffle(double *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            double t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

double energiaCinetica(double massa, double velocidade) {
    return 0.5 * massa * velocidade * velocidade;
}

double energiaPotencial(double massa, double altura) {
    return massa * g * altura;
}

double massaNecessaria(double massa, double altura1, double altura2) {
    return (massa * altura1) / altura2;
}

double velocidadeNoPonto(double energia_total, double massa, double altura) {
    double energia_pot = energiaPotencial(massa, altura);
    if (energia_total < energia_pot)
        return 0;
    return sqrt(2 * (energia_total - energia_pot) / massa);
}

int menuEscolhaMassa(double massas[], int num_opcoes) {
    int opcao;
    printf("Escolha a massa para o próximo trecho:\n");
    for (int i = 0; i < num_opcoes; i++) {
        printf("%d. %.2f kg\n", i + 1, massas[i]);
    }
    printf("Escolha uma opção (1 a %d): ", num_opcoes);
    scanf("%d", &opcao);
    return opcao - 1;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    double massa_inicial, velocidade_inicial, altura_ini, massa_atual, velocidade_atual, massaCerta;
    double alturas[3] = {5.0, 10.0, 15.0}; // Alturas para cada trecho
    int num_trechos = 3;

    printf("Digite a massa do carrinho em movimento (kg): ");
    scanf("%lf", &massa_inicial);
    printf("Velocidade do carrinho em movimento: ");
    scanf("%lf", &velocidade_inicial);
    printf("Altura inicial de referência (h): ");
    scanf("%lf", &altura_ini);

    // Alturas definidas para cada trecho
    double alturas[3] = {5.0 * altura_ini / 4, 3.0 * altura_ini / 4, altura_ini / 2};  // Alturas para os trechos A-B-C, C-D-E, e E-F-G

    massa_atual = massa_inicial * 0.75;  // Massa inicial ajustada
    velocidade_atual = (massa_inicial * velocidade_inicial) / massa_atual;
    distanciaFreio = 3 * altura_ini; // Distância de frenagem

    for (int i = 0; i < num_trechos; i++)
{
    printf("\nTrecho %d\n", i + 1);
    printf("Velocidade atual: %.2f m/s\n", velocidade_atual);
    printf("Massa atual: %.2f kg\n", massa_atual);
    printf("Altura atual: %.2f m\n", alturas[i]);
    printf("Energia Cinética: %.2f J\n", energiaCinetica(massa_atual, velocidade_atual));
    printf("Energia Potencial: %.2f J\n", energiaPotencial(massa_atual, alturas[i]));

        // Calcula a massa necessária para alcançar o topo da próxima seção
        massaCerta = massaNecessaria(massa_atual, altura_ini, alturas[i]);

    // Define opções de massa (2 maiores, 2 menores, e a massa certa)
    double massas[5] = {massaCerta * 1.3, massaCerta * 1.1, massaCerta, massaCerta * 0.9, massaCerta * 0.7};

    // Embaralha as opções de massa
    shuffle(massas, 5);

    // Mostra o menu e obtém a escolha do usuário
    int escolha = menuEscolhaMassa(massas, 5);

    // Verifica se a escolha foi correta
    if (fabs(massas[escolha] - massaCerta) > massaCerta * 0.1)
    {
        if (massas[escolha] > massaCerta)
        {
            printf("Fim de jogo! Pulou para fora do trilho.\n");
        }
        else
        {
            printf("Fim de jogo! Não conseguiu subir os trilhos.\n");
        }
        return 0;
    }
    else
    {
        massa_atual = massas[escolha];
        printf("Massa correta! Continuação para o próximo trecho.\n");

        // Calcula a energia total no início do trecho
        double energia_total = energiaCinetica(massa_atual, velocidade_atual) + energiaPotencial(massa_atual, altura_ini);

        // Atualiza a velocidade com base na energia total e na altura atual
        velocidade_atual = velocidadeNoPonto(energia_total, massa_atual, alturas[i]);
    }
}




    printf("Parabéns! Você completou o passeio na montanha-russa.\n");
    return 0;
}
