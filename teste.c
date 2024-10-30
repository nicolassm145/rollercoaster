#include <stdio.h>
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

    // 1. Colisão elástica no ponto A
    M2 = 1.25 * M;
    v_f = calcularVelocidadeFinalM1(M, M2, V);
    v_2f = calcularVelocidadeFinalM2(M, M2, V);

    // 2. Energia total no ponto B (pós-colisão)
    double energiaCinB = 0.5 * M * v_2f * v_2f; // Energia cinética em B
    double energiaPotB = M2 * GRAVIDADE * altura_ini; // Energia potencial em B
    double energiaTotalB = energiaCinB + energiaPotB;

    for (int i = 0; i < 9; i++) {
        printf("Altura %c: %.2f m\n", 'A' + i, alturas[i]);
    }

    printf("Energia cinética no ponto B: %.2f J\n", energiaCinB);
    printf("Energia potencial no ponto B: %.2f J\n", energiaPotB);
    printf("Energia total no ponto B: %.2f J\n\n", energiaTotalB);

    // 3. Cálculo de massa ajustada para subida de A a C
    M2 = calcularMassaAjustada(energiaTotalB, alturas[2]);
    printf("Massa ajustada para alcançar o ponto C (%.2f): %.2f kg\n\n", alturas[2], M2);

    // 4. Dissipação de energia de C a D para atingir energia necessária em D
    double alturaE = alturas[5]; // Altura do ponto E
    double energiaFinalD = M2 * GRAVIDADE * alturaE; // Energia necessária no ponto D para atingir E
    printf("Energia necessária no ponto D para alcançar o ponto E: %.2f J\n\n", energiaFinalD);

    double energiaDissipadaCD = energiaTotalB - energiaFinalD;
    printf("Energia a ser dissipada entre C e D: %.2f J\n\n", energiaDissipadaCD);

    // 5. Ajustes de massa para E a F e F a G (baseados nas alturas e energia necessária)
    double alturaG = alturas[7];

    // Energia em E: ajustar massa para chegar em F
    double energiaCinE = 0.5 * M2 * v_2f * v_2f;
    M2 = calcularMassaAjustada(energiaCinE, alturaE);
    printf("Massa ajustada para alcançar o ponto E: %.2f kg\n\n", M2);

    // Energia em G: ajustar massa para chegar ao ponto com velocidade nula
    double energiaCinG = 0.5 * M2 * v_2f * v_2f;
    M2 = calcularMassaAjustada(energiaCinG, alturaG);
    printf("Massa ajustada para alcançar o ponto G: %.2f kg\n\n", M2);

    // 6. Parada entre H e I - calcular força para dissipar toda energia cinética restante
    double energiaCinH = 0.5 * M2 * v_2f * v_2f;
    double distanciaHI = 3 * altura_ini;
    double forcaResistenciaHI = energiaCinH / distanciaHI;
    printf("Força de resistência necessária entre H e I para parar: %.2f N\n", forcaResistenciaHI);

    return 0;
}