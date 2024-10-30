// Exercicio 3 - CMAC04
// Felipe Alves Gregorio - 2022008250
// Nícolas de Souza Moreira - 2022014472

#include <stdio.h>
#include <stdlib.h>

#define GRAVIDADE 10.0

// Funções auxiliares
double calcularVelocidadeFinalM1(double M1, double M2, double V) {
    return ((M1 - M2) * V) / (M1 + M2);
}

double calcularVelocidadeFinalM2(double M1, double M2, double V) {
    return (2 * M1 * V) / (M1 + M2);
}

double calcularMassaAjustada(double energiaCinInicial, double altura) {
    return energiaCinInicial / (GRAVIDADE * altura);
}

// Função para calcular o coeficiente de atrito
double calcularCoeficienteAtrito(double energiaDissipada, double massa) {
    double forcaResistencia = energiaDissipada;
    double forcaNormal = massa * GRAVIDADE;
    return forcaResistencia / forcaNormal;
}

// Função para verificar a massa escolhida pelo usuario
int verificarMassaEscolhida(double massaCorreta, double massaEscolhida) {
    double erro = 0.1 * massaCorreta;
    if (massaEscolhida >= massaCorreta - erro && massaEscolhida <= massaCorreta + erro) {
        printf("A massa foi ajustada para o valor correto: %.2f kg\n\n", massaCorreta);
        return 1; // Massa correta dentro de 10% de erro
    } else {
        printf("Erro! A massa escolhida esta fora do limite permitido.\nJogo encerrado.\n\n");
        return 0; // Massa incorreta
    }
}

int main() {
    double M, V, altura_ini, M2, v_f, v_2f;

    // Entrada dos valores iniciais
    printf("Digite a massa do carrinho M (kg): ");
    scanf("%lf", &M);
    printf("Digite a velocidade inicial V (m/s): ");
    scanf("%lf", &V);
    printf("Digite a altura inicial H entre os pontos A e B (m): ");
    scanf("%lf", &altura_ini);

    // Definindo as alturas relativas à altura inicial H
    double alturas[9] = {
        altura_ini,                     // hA
        0,                              // hB
        altura_ini * 5 / 4,             // hC
        0,                              // hD
        altura_ini * 3 / 4,             // hE
        0,                              // hF
        altura_ini / 2,                 // hG
        altura_ini * (1.0 / 2.0 - 3.0 / 8.0), // hH = H/8
        altura_ini * 3 / 8              // hI = H/8
    };

    // 1. Colisao elastica no ponto A
    M2 = 1.25 * M;
    v_f = calcularVelocidadeFinalM1(M, M2, V);
    v_2f = calcularVelocidadeFinalM2(M, M2, V);

    // 2. Energia total no ponto B (pos-colisao)
    double energiaCinB = 0.5 * M * v_2f * v_2f; // Energia cinetica em B
    double energiaPotB = M2 * GRAVIDADE * altura_ini; // Energia potencial em B
    double energiaTotalB = energiaCinB + energiaPotB;

    for (int i = 0; i < 9; i++) {
        printf("Altura %c: %.2f m\n", 'A' + i, alturas[i]);
    }

    printf("Energia cinetica no ponto B: %.2f J\n", energiaCinB);
    printf("Energia potencial no ponto B: %.2f J\n", energiaPotB);
    printf("Energia total no ponto B: %.2f J\n\n", energiaTotalB);

    // 3. Calculo de massa ajustada para subida de A a C
    M2 = calcularMassaAjustada(energiaTotalB, alturas[2]);
    printf("Massa ajustada para alcancar o ponto C (%.2f): %.2f kg\n\n", alturas[2], M2);

    // Entrada da massa escolhida pelo jogador no ponto B
    double massaEscolhidaB;
    printf("Escolha a massa para o ponto B (intervalo permitido: %.2f kg a %.2f kg): ",
           M2 * 0.7, M2 * 1.3);
    scanf("%lf", &massaEscolhidaB);

    if (!verificarMassaEscolhida(M2, massaEscolhidaB)) {
        return 0;
    }

    // 4. Dissipacao de energia de C a D para atingir energia necessaria em D
    double alturaE = alturas[4]; // Altura do ponto E
    double energiaFinalD = M2 * GRAVIDADE * alturaE; // Energia necessaria no ponto D para atingir E
    printf("Energia necessaria no ponto D para alcancar o ponto E: %.2f J\n\n", energiaFinalD);

    double energiaDissipadaCD = energiaTotalB - energiaFinalD;
    printf("Energia a ser dissipada entre C e D: %.2f J\n\n", energiaDissipadaCD);

    // 5. Calculo do coeficiente de atrito entre C e D
    double coeficienteAtritoCD = calcularCoeficienteAtrito(energiaDissipadaCD, M2);
    printf("Coeficiente de atrito necessario entre C e D: %.2f\n", coeficienteAtritoCD);

    // 6. Ajustes de massa para E a F e F a G (baseados nas alturas e energia necessaria)
    double alturaG = alturas[6];

    // Energia em E: ajustar massa para chegar em F
    double energiaCinE = 0.5 * M2 * v_2f * v_2f;
    M2 = calcularMassaAjustada(energiaCinE, alturaE);
    //printf("Massa ajustada para alcancar o ponto E: %.2f kg\n\n", M2);

    // Entrada da massa escolhida pelo jogador no ponto F
    double massaEscolhidaF;
    printf("Escolha a massa para o ponto F (intervalo permitido: %.2f kg a %.2f kg): ",
           M2 * 0.7, M2 * 1.3);
    scanf("%lf", &massaEscolhidaF);

    if (!verificarMassaEscolhida(M2, massaEscolhidaF)) {
        return 0;
    }

    // 7. Parada entre H e I - calcular forca para dissipar toda energia cinetica restante
    double energiaCinH = 0.5 * M2 * v_2f * v_2f;
    double distanciaHI = 3 * altura_ini;
    double forcaResistenciaHI = energiaCinH / distanciaHI;
    printf("Forca de resistencia necessaria entre H e I para parar: %.2f N\n", forcaResistenciaHI);

    printf("Parabens! Voce concluiu o trajeto com sucesso.\n");

    return 0;
}
