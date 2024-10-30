// Exercicio 3 - CMAC04
// Felipe Alves Gregorio - 2022008250
// Nícolas de Souza Moreira - 2022014472

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define GRAVIDADE 10

// Funções para calcular energia cinética e potencial
float calcular_energia_cinetica(float massa, float velocidade)
{
    return (massa * velocidade * velocidade) / 2;
}

float calcular_energia_potencial(float massa, float altura)
{
    return massa * GRAVIDADE * altura;
}

// Função para calcular a nova velocidade
float calcular_velocidade(float energia_total, float massa, float altura)
{
    return sqrt(2 * (energia_total - calcular_energia_potencial(massa, altura)) / massa);
}

// Função para calcular a massa necessária para alcançar a próxima altura
float massaNecessaria(float massa_atual, float altura_atual, float altura_prox, float velocidade_atual) {
    float energia_cinetica_atual = calcular_energia_cinetica(massa_atual, velocidade_atual);
    float energia_potencial_prox = calcular_energia_potencial(massa_atual, altura_prox);

    // Calcula a energia necessária para alcançar a próxima altura
    float energia_necessaria = energia_potencial_prox - calcular_energia_potencial(massa_atual, altura_atual);

    // Se a energia cinética atual for maior ou igual à energia necessária, não precisamos ajustar a massa
    if (energia_cinetica_atual >= energia_necessaria) {
        return massa_atual; // Retorna a massa atual, pois não há necessidade de mudança
    }

    // Caso contrário, calculamos a nova massa necessária
    return (energia_necessaria - energia_cinetica_atual) / GRAVIDADE; // Usamos a gravidade para encontrar a nova massa
}

// Função para embaralhar as opções de massa
void shuffle(float *massas, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        float temp = massas[i];
        massas[i] = massas[j];
        massas[j] = temp;
    }
}

// Função para mostrar o menu e obter a escolha do usuário
int menuEscolhaMassa(float *massas, int n)
{
    printf("Escolha uma massa:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d: %.2f kg\n", i + 1, massas[i]);
    }
    int escolha;
    scanf("%d", &escolha);
    return escolha - 1; // Retorna o índice da massa escolhida
}

int main(void)
{
    float massa_atual, massa_inicial, velocidade_inicial, altura_ini;
    int num_trechos = 9; // Número de trechos

    // Solicita a altura inicial do usuário
    printf("Digite a altura inicial em metros: ");
    scanf("%f", &altura_ini);

    // Definindo as alturas relativas à altura inicial
    float alturas[9] = {
        altura_ini,                           // hA
        0,                                    // hB
        altura_ini * 5 / 4,                   // hC
        0,                                    // hD
        altura_ini * 5 / 4,                   // hE
        0,                                    // hF
        altura_ini * 3 / 8,                   // hG
        altura_ini * (1.0 / 2.0 - 3.0 / 8.0), // hH
        altura_ini * (1.0 / 2.0 - 3.0 / 8.0)  // hI
    };

    printf("Digite a massa do carrinho em kg: ");
    scanf("%f", &massa_inicial);
    massa_atual = massa_inicial * 1.25;
    printf("Digite a velocidade do carrinho em m/s: ");
    scanf("%f", &velocidade_inicial);

    // Calcula a energia total inicial
    float energia_total = calcular_energia_cinetica(massa_atual, velocidade_inicial) + calcular_energia_potencial(massa_atual, altura_ini);
    printf("Altura inicial: %.2f m\n", altura_ini);

    for (int i = 0; i < num_trechos; i++)
    {
        // Atualiza a altura atual
        float altura_atual = alturas[i];

        // Atualiza a velocidade com base na energia total e na altura atual
        float velocidade_atual = calcular_velocidade(energia_total, massa_atual, altura_atual);

        printf("\nTrecho %d\n", i + 1);
        printf("Velocidade atual: %.2f m/s\n", velocidade_atual);
        printf("Massa atual: %.2f kg\n", massa_atual);
        printf("Altura atual: %.2f m\n", altura_atual);
        printf("Energia Cinética: %.2f J\n", calcular_energia_cinetica(massa_atual, velocidade_atual));
        printf("Energia Potencial: %.2f J\n", calcular_energia_potencial(massa_atual, altura_atual));

        // Verifica se não está no último trecho e se está subindo
        if (i < num_trechos - 1 && alturas[i] < alturas[i + 1])
        {
            // Calcula a massa necessária para alcançar o topo da próxima seção
            float massaCerta = massaNecessaria(massa_atual, alturas[i], alturas[i + 1], velocidade_atual);

            // Define opções de massa
            float massas[5] = {massaCerta * 1.3, massaCerta * 1.1, massaCerta, massaCerta * 0.9, massaCerta * 0.7};
            shuffle(massas, 5);

            // Obtém a escolha do usuário
            int escolha = menuEscolhaMassa(massas, 5);
            massa_atual = massas[escolha];
            // Verifica se a escolha foi correta
            if (fabs(massa_atual - massaCerta) > massaCerta * 0.1)
            {
                if (massa_atual > massaCerta)
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
                massa_atual = massa_atual;
                printf("Massa correta! Continuação para o próximo trecho.\n");
            }
        }

        // Atualiza a energia total com a nova velocidade e altura
        energia_total = calcular_energia_cinetica(massa_atual, velocidade_atual) + calcular_energia_potencial(massa_atual, altura_atual);
    }

    return 0;
}