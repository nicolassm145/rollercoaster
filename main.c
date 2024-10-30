#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVIDADE 10.0

// Funções auxiliares
double calcularVelocidadeFinalM2(double M1, double M2, double V)
{
    return (2 * M1 * V) / (M1 + M2);
}

double calcularMassaAjustada(double energiaCinInicial, double altura)
{
    return energiaCinInicial / (GRAVIDADE * altura);
}

double calcularNovaGravidade(double energiaTotal, double massa, double altura)
{
    return energiaTotal / (massa * altura);
}

int verificarMassaEscolhida(double massaCorreta, double massaEscolhida)
{
    double erro = 0.1 * massaCorreta;
    if (massaEscolhida >= massaCorreta - erro && massaEscolhida <= massaCorreta + erro)
    {
        printf("A massa esolhido está correto (o suficiente) e foi ajustada para o valor correto: %.2f kg\n\n", massaCorreta);
        return 1; // Massa correta dentro de 10% de erro
    }
    else
    {
        printf("Erro! A massa escolhida estava incorreta.\n");
        printf("O valor correto era: %.2f kg\n", massaCorreta);
        return 0; // Massa incorreta
    }
}

int verificarGravidadeEscolhida(double gravidadeCorreta, double gravidadeEscolhida)
{
    double erro = 0.1 * gravidadeCorreta;
    if (gravidadeEscolhida >= gravidadeCorreta - erro && gravidadeEscolhida <= gravidadeCorreta + erro)
    {
        printf("A gravidade escolhida está correta (o suficiente) e foi ajustada para o valor correto: %.2f m/s^2\n\n", gravidadeCorreta);
        return 1; // Gravidade correta dentro de 10% de erro
    }
    else
    {
        printf("Erro! A gravidade escolhida estava incorreta.\n");
        printf("O valor correto era: %.2f m/s^2\n", gravidadeCorreta);
        return 0; // Gravidade incorreta
    }
}

int verificarForcaEscolhida(double forcaCorreta, double forcaEscolhida)
{
    double erro = 0.1 * forcaCorreta;
    if (forcaEscolhida >= forcaCorreta - erro && forcaEscolhida <= forcaCorreta + erro)
    {
        printf("A forca escolhida está correta (o suficiente) e foi ajustada para o valor correto: %.2f N\n\n", forcaCorreta);
        return 1; // Forca correta dentro de 10% de erro
    }
    else
    {
        printf("Erro! A forca escolhida estava incorreta.\n");
        printf("O valor correto era: %.2f N\n", forcaCorreta);
        return 0; // Forca incorreta
    }
}

void jogar()
{
    double M, V, altura_ini, M2, v_2f;

    // Entrada dos valores iniciais
    printf("Digite a massa do carrinho M (kg): ");
    scanf("%lf", &M);
    printf("Digite a velocidade inicial V (m/s): ");
    scanf("%lf", &V);
    printf("Digite a altura inicial H entre os pontos A e B (m): ");
    scanf("%lf", &altura_ini);

    // Definindo as alturas relativas à altura inicial H
    double alturas[9] = {
        altura_ini,                           // hA
        0,                                    // hB
        altura_ini * 5 / 4,                   // hC
        0,                                    // hD
        altura_ini * 3 / 4,                   // hE
        0,                                    // hF
        altura_ini / 2,                       // hG
        altura_ini * (1.0 / 2.0 - 3.0 / 8.0), // hH = H/8
        altura_ini * 3 / 8                    // hI = H/8
    };

    for (int i = 0; i < 9; i++)
    {
        printf("\nAltura %c: %.2f m\n", 'A' + i, alturas[i]);
    }

    // 1. Colisão elástica no ponto A
    M2 = 1.25 * M;
    v_2f = calcularVelocidadeFinalM2(M, M2, V);
    printf("A massa atual e de: %.2f kg\n\n", M2);

    double energiaCinA = 0.5 * M2 * v_2f * v_2f;
    double energiaPotA = M2 * GRAVIDADE * altura_ini;
    double energiaTotalA = energiaCinA + energiaPotA;

    printf("Energia cinetica no ponto A: %.2f J\n", energiaCinA);
    printf("Energia potencial no ponto A: %.2f J\n", energiaPotA);
    printf("Energia total no ponto A: %.2f J\n\n", energiaTotalA);

    // Energias no ponto B
    double energiaPotB = M2 * GRAVIDADE * alturas[1];
    double energiaCinB = energiaTotalA - energiaPotB;
    double energiaTotalB = energiaCinB + energiaPotB;

    printf("Energia cinetica no ponto B: %.2f J\n", energiaCinB);
    printf("Energia potencial no ponto B: %.2f J\n", energiaPotB);
    printf("Energia total no ponto B: %.2f J\n\n", energiaTotalB);

    // Calculo da energia necessária para alcancar o ponto C
    printf("Agora, para que o carrinho consiga chegar ao ponto C %.2f m, precisamos alterar a massa.\nA massa atual e de: %.2f kg\n\n", alturas[2], M2);

    // Entrada da massa escolhida pelo jogador no ponto B
    double massaEscolhidaB;
    printf("Escolha a massa para o ponto B (intervalo permitido: %.2f kg a %.2f kg): ",
           calcularMassaAjustada(energiaTotalB, M2) * 0.7, calcularMassaAjustada(energiaTotalB, M2) * 1.3);
    scanf("%lf", &massaEscolhidaB);

    if (!verificarMassaEscolhida(calcularMassaAjustada(energiaTotalB, M2), massaEscolhidaB))
    {
        return;
    }

    M2 = calcularMassaAjustada(energiaTotalB, M2);
    energiaPotB = M2 * GRAVIDADE * alturas[1];
    energiaCinB = energiaTotalB - energiaPotB;
    energiaTotalB = energiaCinB + energiaPotB;

    // Energias no ponto C
    double energiaPotC = M2 * GRAVIDADE * alturas[2];
    double energiaCinC = energiaTotalB - energiaPotC;
    double energiaTotalC = energiaCinC + energiaPotC;

    printf("Energia cinetica no ponto C: %.2f J\n", energiaCinC);
    printf("Energia potencial no ponto C: %.2f J\n", energiaPotC);
    printf("Energia total no ponto C: %.2f J\n\n", energiaTotalC);

    // 4. Dissipação de energia de C a D para atingir energia necessária em D para alcancar E
    double alturaE = alturas[4];                     // Altura do ponto E
    double energiaFinalD = M2 * GRAVIDADE * alturaE; // Energia necessária no ponto D para atingir E
    printf("Energia necessária no ponto D para alcancar o ponto E: %.2f J\n\n", energiaFinalD);
    printf("Agora precisamos dissipar energia entre C e D para que o carrinho consiga alcancar o ponto E e nao decolar.\n");
    printf("Para isso, vamos alterar a aceleracao da gravidade.\n");

    double novaGravidade = calcularNovaGravidade(energiaFinalD, M2, fabs(alturas[2] - alturas[3]));
    double novaGravidadeEscolhida;
    printf("Escolha a nova gravidade para o trecho entre C e D (intervalo permitido: %.2f m/s^2 a %.2f m/s^2): ", novaGravidade * 0.7, novaGravidade * 1.2);
    scanf("%lf", &novaGravidadeEscolhida);

    if (!verificarGravidadeEscolhida(novaGravidade, novaGravidadeEscolhida))
    {
        return;
    }

    double energiaDissipadaCD = energiaTotalC - energiaFinalD;
    printf("Energia dissipada entre C e D: %.2f J\n\n", energiaDissipadaCD);

    double energiaPotD = M2 * GRAVIDADE * alturas[3];
    double energiaCinD = energiaFinalD - energiaPotD;
    double energiaTotalD = energiaCinD + energiaPotD;

    printf("Energia cinetica no ponto D: %.2f J\n", energiaCinD);
    printf("Energia potencial no ponto D: %.2f J\n", energiaPotD);
    printf("Energia total no ponto D: %.2f J\n\n", energiaTotalD);

    // Energias no ponto E
    double energiaPotE = M2 * GRAVIDADE * alturas[4];
    double energiaCinE = energiaTotalD - energiaPotE;
    double energiaTotalE = energiaCinE + energiaPotE;

    printf("Energia cinetica no ponto E: %.2f J\n", energiaCinE);
    printf("Energia potencial no ponto E: %.2f J\n", energiaPotE);
    printf("Energia total no ponto E: %.2f J\n\n", energiaTotalE);

    // Energias no ponto F
    double energiaPotF = M2 * GRAVIDADE * alturas[5];
    double energiaCinF = energiaTotalE - energiaPotF;
    double energiaTotalF = energiaCinF + energiaPotF;

    printf("Energia cinetica no ponto F: %.2f J\n", energiaCinF);
    printf("Energia potencial no ponto F: %.2f J\n", energiaPotF);
    printf("Energia total no ponto F: %.2f J\n\n", energiaTotalF);

    // Ajuste de massa para alcancar o ponto G
    printf("Agora, para que o carrinho consiga alcancar o ponto G %.2f m, precisamos alterar a massa.\nA massa atual e de: %.2f kg\n\n", alturas[6], M2);

    double massaEscolhidaF;
    printf("Escolha a massa para o ponto F (intervalo permitido: %.2f kg a %.2f kg): ",
           calcularMassaAjustada(energiaTotalE, M2) * 0.7, calcularMassaAjustada(energiaTotalE, M2) * 1.3);
    scanf("%lf", &massaEscolhidaF);

    if (!verificarMassaEscolhida(calcularMassaAjustada(energiaTotalE, M2), massaEscolhidaF))
    {
        return;
    }

    M2 = calcularMassaAjustada(energiaTotalE, M2);
    energiaPotE = M2 * GRAVIDADE * alturas[4];
    energiaCinE = energiaTotalE - energiaPotE;
    energiaTotalE = energiaCinE + energiaPotE;

    // Energias no ponto G
    double energiaPotG = M2 * GRAVIDADE * alturas[6];
    double energiaCinG = energiaTotalE - energiaPotG;
    double energiaTotalG = energiaCinG + energiaPotG;

    printf("Energia cinetica no ponto G: %.2f J\n", energiaCinG);
    printf("Energia potencial no ponto G: %.2f J\n", energiaPotG);
    printf("Energia total no ponto G: %.2f J\n\n", energiaTotalG);

    // 7. Parada entre H e I - calcular forca para dissipar toda energia cinetica restante
    double energiaPotH = M2 * GRAVIDADE * alturas[7];
    double energiaCinH = energiaTotalG - energiaPotH;
    double energiaTotalH = energiaCinH + energiaPotH;
    double distanciaHI = 3 * altura_ini;

    printf("Energia cinetica no ponto H: %.2f J\n", energiaCinH);
    printf("Energia potencial no ponto H: %.2f J\n", energiaPotH);
    printf("Energia total no ponto H: %.2f J\n\n", energiaTotalG);

    double forcaResistenciaHI = energiaTotalH / distanciaHI;
    double forcaEscolhidaHI;
    printf("Agora precisamos aplicar uma forca de resistencia para parar o carrinho antes que ele caia da rampa.\n");
    printf("Escolha a forca de resistencia para aplicar no carrinho (intervalo permitido: %.2f N a %.2f N): ", forcaResistenciaHI * 0.7, forcaResistenciaHI * 1.3);
    scanf("%lf", &forcaEscolhidaHI);

    if (!verificarForcaEscolhida(forcaResistenciaHI, forcaEscolhidaHI))
    {
        return;
    }

    printf("\n\nParabens! Voce concluiu o trajeto com sucesso.\n\n");
    printf("Obrigado por jogar!\n\n\n");
}

int main()
{
    int opcao;
    do
    {
        printf("Bem-vindo ao jogo do carrinho!\n");
        printf("Neste jogo, voce deve alterar a massa, a gravidade e a forca para guiar um carrinho por um trilho.\n");
        printf("Caso voce erre, sera informado qual era a opcao correta e tera a opcao de sair ou jogar novamente.\n");
        printf("1. Jogar\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            jogar();
            break;
        case 2:
            printf("Saindo do jogo. Ate mais!\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 2);

    return 0;
}
