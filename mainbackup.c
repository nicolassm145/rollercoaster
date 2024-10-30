// Exercicio 3 - CMAC04
// Felipe Alves Gregorio - 2022008250
// Nícolas de Souza Moreira - 2022014472

#include <stdio.h>
#include <math.h>

#define g 10

double energiaCinetica(double massa, double velocidade)
{
    return 0.5 * massa * velocidade * velocidade;
}

double energiaPotencial(double massa, double altura)
{
    return massa * g * altura;
}

double massaNecessaria(double massa, double altura1, double altura2)
{
    double massa2;
    massa2 = (massa * altura1) / altura2;
    return massa2;
}

double velocidadeNoPonto(double energia_total, double massa, double altura)
{
    double energia_pot = energiaPotencial(massa, altura);
    if (energia_total < energia_pot)
        return 0;
    return sqrt(2 * (energia_total - energia_pot) / massa);
}

void alterar_massa(double *massa_atual, double massaCerta, int opcao) {
    if (opcao == 1) {
        *massa_atual = massaCerta * 0.80;
        printf("Massa ajustada para: %.2f kg\n", *massa_atual);
    }
    else if (opcao == 2) {
        *massa_atual = massaCerta * 0.90;
        printf("Massa ajustada para: %.2f kg\n", *massa_atual);
    }
    else if (opcao == 3) {
        *massa_atual = massaCerta;
        printf("Massa ajustada para o valor exato.\n");
    }
    else if (opcao == 4) {
        *massa_atual = massaCerta * 1.10; 
        printf("Massa ajustada para: %.2f kg\n", *massa_atual);
    }
    else if (opcao == 5) {
        *massa_atual = massaCerta * 1.20; 
        printf("Massa ajustada para: %.2f kg\n", *massa_atual);
    }
    else {
        printf("Opção inválida.\n");
    }
}

int mostrar_menu(double massaCerta) {
    int opcao;
    printf("\nMenu de Opções:\n");
    printf("1. Alterar para: \n", massaCerta * 0.80);
    printf("2. Alterar para: \n", massaCerta * 0.90);
    printf("3. Alterar para: \n", massaCerta);
    printf("4. Alterar para: \n", massaCerta * 1.10);
    printf("5. Alterar para: \n", massaCerta * 1.20);
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

int main()
{
    double massa_inicial, velocidade_inicial, altura_ini, alturaC, alturaE, alturaG, energia_total, massa_atual, velocidade_atual, massaCerta;
    int opcao;

    printf("Digite a massa do carrinho em movimento(kg): ");
    scanf("%lf", &massa_inicial);

    printf("Velocidade do carrinho em movimento: ");
    scanf("%lf", &velocidade_inicial);

    printf("Altura inicial referencial: ");
    scanf("%lf", &altura_ini);

    massa_atual = massa_inicial * 1.25;
    massaCerta = massaNecessaria(massa_atual, altura_ini, altura_ini * 5 / 4);

    velocidade_atual = (massa_inicial * velocidade_inicial) / (massa_atual);

    energia_total = energiaCinetica(massa_atual, velocidade_atual) + energiaPotencial(massa_atual, altura_ini);

    velocidade_atual = velocidade_atual + velocidadeNoPonto(energia_total, massa_atual, altura_ini);

    printf("A velocidade atual é: %lf\n", velocidade_atual);
    printf("DEBUG: A massa necessaria para conseguir subir é: %lf\n", massaCerta);

    for (int i = 0; i < 3; i++)
    {
        printf("Digite a altura do ponto %d: ", i + 1);
        opcao = mostrar_menu(massaCerta);
        if (opcao != 3)
        {
            alterar_massa(&massa_atual, massaCerta, opcao);
        }
    }

    return 0;
}