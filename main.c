// Exercicio 3 - CMAC04
// Felipe Alves Gregorio - 2022008250
// Nícolas de Souza Moreira - 2022014472

#include <stdio.h>
#include <math.h>


int main(void) {
    float m1, m2, m3, m4, v1, v2, hab, hbc, hcd, hde, hef, hfg, hgh, hPossivel, hConseguido, eca, ecb, ecc, ecd, ece, ecf, ecg, ech, epa, epb, epc, epd, epe, epf, epg, eph, g, x, vb, vc, vd, ve, vf, vg, vh, respostaid, a, atrito, pont, eh, ei, epi, ef, eih;
    g = 10;
    char resposta;

    pont = 0;	//pontuação

    printf("Seja muito bem-vindo(a) à Simulação!\nUm carrinho percorrerá uma montanha-russa de pontos que vão de A até I em um sobe e desce. Serão necessárias algumas alterações para que o carrinho percorra o trajeto corretamente. Vamos lá!?\n\n");
    printf("Digite a massa do carrinho em kg: ");	//coletando informações
    scanf("%f", &m1);
    printf("Digite a velocidade do carrinho em m/s: ");
    scanf("%f", &v1);
    printf("Digite a altura referencial H entre os pontos A e B em metros: ");
    scanf("%f", &hab);

    m2 = m1 * 1.25;	//cálculo da massa do segundo carrinho

    v2 = (m1 * v1) / m2;	// m1 * v1 = m1 * 0 + m2 * v2

    eca = (0.5 * m2 * v2 * v2);	// energia cinética no ponto A

    epa = m2 * g * hab;	// energia potencial no ponto A

    printf("O carrinho colide com outro gerando, neste outro carrinho, de massa %.2f kg (1.25x maior), uma velocidade de %.2f m/s.\n", m2, v2);	// fornecendo as informações do carrinho que fará o percurso

    // Alturas:
    hbc = hab * 5 / 4;
    hcd = hbc;
    hde = hab * 3 / 8;
    hef = hde;
    hfg = hab / 2;
    hgh = (1.0 / 2 - 3.0 / 8) * hab;

    printf("\nPONTO A:\n");	// informações no ponto A
    printf("- Energia cinética: %.3f J;\n", eca);
    printf("- Energia potencial gravitacional: %.3f J;\n", epa);
    printf("- Velocidade: %.2f m/s.\n", v2);

    printf("\nDepois, o carrinho tem uma queda de %.2f m até o ponto B.\n", hab);	// o que acontece depois

    ecb = eca + m2 * g * hab;	// energia cinética no ponto B (conservação de energia)
    vb = sqrt(ecb * 2 / m2);	// velocidade no ponto B

    epb = 0;	// energia potencial é zero pois "não tem altura"

    printf("\nPONTO B:\n");	// informações do ponto B
    printf("- Energia cinética: %.3f J;\n", ecb);
    printf("- Energia potencial gravitacional: %.3f J;\n", epb);
    printf("- Velocidade: %.2f m/s.\n", vb);

    epc = m2 * g * hbc;	// energia potencial no ponto C

    hPossivel = (m2 * vb * vb) / (2 * m2 * g);	// altura possível de ser alcançada (conservação de energia)

    printf("\nAgora, o carrinho necessita subir %.2f m até o Ponto C.", hbc);

    if (hbc != hPossivel) {	// caso ele não consiga atingir a altura necessária (ou passe dela)
        printf("\nA altura que o carrinho conseguirá atingir é %.2f m, mas ele precisa atingir %.2f.", hPossivel, hbc);
        printf("\nPara chegar ao Ponto C (precisamente), será necessária uma mudança mágica na massa do carrinho. Digite a nova massa: ");
        scanf("%f", &m3);	// alteração na massa

        hConseguido = (m2 * vb * vb) / (2 * m3 * g);	// cálculo da altura com a nova massa

        if (hConseguido <= hPossivel + 1 && hConseguido >= hPossivel - 1) {	// checagem se o usuário acertou a resposta
            printf("Resposta certa!!!\n");
            m3 = (m2 * vb * vb) / (2 * hbc * g);	// cálculo da massa correta
            pont++;
        } else {
            m3 = (m2 * vb * vb) / (2 * hbc * g);	// mesmo cálculo da massa
            printf("Resposta errada. O correto seria %.2f kg. Seguiremos utilizando o valor correto.\n", m3);	// mensagem de erro
        }
    } else {
        m3 = m2;	// caso tudo esteja dando certo sem precisar de mudança na massa
    }

    ecc = 0;	// energia cinética nula, apenas com energia potencial

    epc = m3 * g * hcd;	// cálculo da energia potencial no ponto C

    vc = 0;	// velocidade em C é nula

    printf("\nPONTO C:\n");	// informações do ponto C
    printf("- Energia cinética: %.3f J;\n", ecc);
    printf("- Energia potencial gravitacional: %.3f J;\n", epc);
    printf("- Velocidade: %.2f m/s.\n", vc);

    ecd = epc;	// conservação de energia

    epd = 0;

    vd = sqrt(ecd * 2 / m3);	// cálculo da velocidade em D

    printf("\nDepois de C, o carrinho desce %.2f m até o ponto D.\n", hcd);

    printf("\nPONTO D:\n");	// informações do ponto D
    printf("- Energia cinética: %.3f J;\n", ecd);
    printf("- Energia potencial gravitacional: %.3f J;\n", epd);
    printf("- Velocidade: %.2f m/s.\n", vd);

    epe = m3 * g * hde;	// energia potencial em E

    x = (10 * epe) / ecd; // nova aceleração da gravidade

    if (epe != ecd) {	// caso a energia potencial em E seja diferente da energia cinética em D
        printf("\nAgora, para subir %.2f m até o ponto E, faremos uma mudança no trecho CD. Assim como alteramos a massa para atingir C, alteraremos a aceleração da gravidade para atingirmos E precisamente.\n", hde);
        respostaid = 0;
        while (respostaid != 1) {	// while para esperar uma resposta que satisfaça
            printf("Aceita uma dica? s ou n? A resposta certa valerá 0.5 pontos. ");	// dica
            scanf(" %c", &resposta);
            if (resposta == 's') {
                ecd = epc * x / 10;	// cálculo da nova energia cinética em D
                printf("A nova energia cinética em D será %.3f J.\n", ecd);
                respostaid = 1;
            } else if (resposta == 'n') {
                printf("Ok.\n");
                respostaid = 1;
            } else {
                printf("Não entendi a resposta...\n");
            }
        }
        printf("Qual a nova aceleração da gravidade para C-D? ");
        scanf("%f", &g);
        if (g <= x + 0.1 && g >= x - 0.1) {	// novamente com margem de erro
            printf("Resposta certa!!!\n");
            if (resposta == 's') {
                pont += 0.5;
            } else {
                pont++;
            }
        } else {
            printf("Resposta errada. O correto seria %.2f m/s². Seguiremos utilizando o valor correto.\n", x);
        }
    } else {	// caso não seja
        printf("\nAgora, o carrinho sobe %.2f m até o ponto E.\n", hde);
    }

    ece = 0;	// energia cinética nula

    ve = 0;

    printf("\nPONTO E:\n");	// informações do ponto E
    printf("- Energia cinética: %.3f J;\n", ece);
    printf("- Energia potencial gravitacional: %.3f J;\n", epe);
    printf("- Velocidade: %.2f m/s.\n", ve);

    printf("\nDepois, o carrinho desce %.2f m até o ponto F.\n", hde);	// desce até F

    ef = epe;	// energia potencial em E igual à cinética em F

    epf = 0;	// energia potencial é zero

    vf = sqrt(ef * 2 / m3);	// velocidade em F

    printf("\nPONTO F:\n");	// informações do ponto F
    printf("- Energia cinética: %.3f J;\n", ef);
    printf("- Energia potencial gravitacional: %.3f J;\n", epf);
    printf("- Velocidade: %.2f m/s.\n", vf);

    epg = m3 * g * hfg;	// energia potencial em G

    if (epg != ef) {	// caso a energia potencial em G seja diferente da energia cinética em F
        printf("\nAgora, para subir %.2f m até o ponto G, faremos uma mudança no trecho EF. Assim como alteramos a massa para atingir C, alteraremos a aceleração da gravidade para atingirmos G precisamente.\n", hfg);
        respostaid = 0;
        while (respostaid != 1) {	// while para esperar uma resposta que satisfaça
            printf("Aceita uma dica? s ou n? A resposta certa valerá 0.5 pontos. ");	// dica
            scanf(" %c", &resposta);
            if (resposta == 's') {
                ef = epg * x / 10;	// cálculo da nova energia cinética em F
                printf("A nova energia cinética em F será %.3f J.\n", ef);
                respostaid = 1;
            } else if (resposta == 'n') {
                printf("Ok.\n");
                respostaid = 1;
            } else {
                printf("Não entendi a resposta...\n");
            }
        }
        printf("Qual a nova aceleração da gravidade para E-F? ");
        scanf("%f", &g);
        if (g <= x + 0.1 && g >= x - 0.1) {	// novamente com margem de erro
            printf("Resposta certa!!!\n");
            if (resposta == 's') {
                pont += 0.5;
            } else {
                pont++;
            }
        } else {
            printf("Resposta errada. O correto seria %.2f m/s². Seguiremos utilizando o valor correto.\n", x);
        }
    } else {	// caso não seja
        printf("\nAgora, o carrinho sobe %.2f m até o ponto G.\n", hfg);
    }

    ech = 0;	// energia cinética nula

    vh = 0;	// velocidade em H

    printf("\nPONTO G:\n");	// informações do ponto G
    printf("- Energia cinética: %.3f J;\n", ech);
    printf("- Energia potencial gravitacional: %.3f J;\n", epg);
    printf("- Velocidade: %.2f m/s.\n", vh);

    printf("\nDepois, o carrinho desce %.2f m até o ponto H.\n", hfg);	// desce até H

    eh = epg;	// energia potencial em G igual à cinética em H

    eph = 0;	// energia potencial é zero

    vh = sqrt(eh * 2 / m3);	// velocidade em H

    printf("\nPONTO H:\n");	// informações do ponto H
    printf("- Energia cinética: %.3f J;\n", eh);
    printf("- Energia potencial gravitacional: %.3f J;\n", eph);
    printf("- Velocidade: %.2f m/s.\n", vh);

    printf("\nPor último, o carrinho sobe %.2f m até o ponto I.\n", hgh);	// sobe até I

    ei = eh;	// energia cinética em H igual à potencial em I

    epi = m3 * g * hgh;	// energia potencial em I

    if (epi != eh) {	// se a energia potencial em I for diferente da energia cinética em H
        printf("Para subir até o ponto I, faremos uma mudança no trecho GH. Assim como alteramos a massa para atingir C, alteraremos a aceleração da gravidade para atingirmos I precisamente.\n");	// nova mudança
        respostaid = 0;
        while (respostaid != 1) {	// while para esperar uma resposta que satisfaça
            printf("Aceita uma dica? s ou n? A resposta certa valerá 0.5 pontos. ");	// dica
            scanf(" %c", &resposta);
            if (resposta == 's') {
                eh = epi * x / 10;	// nova energia cinética em H
                printf("A nova energia cinética em H será %.3f J.\n", eh);
                respostaid = 1;
            } else if (resposta == 'n') {
                printf("Ok.\n");
                respostaid = 1;
            } else {
                printf("Não entendi a resposta...\n");
            }
        }
        printf("Qual a nova aceleração da gravidade para G-H? ");
        scanf("%f", &g);
        if (g <= x + 0.1 && g >= x - 0.1) {	// novamente com margem de erro
            printf("Resposta certa!!!\n");
            if (resposta == 's') {
                pont += 0.5;
            } else {
                pont++;
            }
        } else {
            printf("Resposta errada. O correto seria %.2f m/s². Seguiremos utilizando o valor correto.\n", x);
        }
    } else {	// caso não seja
        printf("\nAgora, o carrinho sobe %.2f m até o ponto I.\n", hgh);
    }

    eih = 0;	// energia cinética nula

    printf("\nPONTO I:\n");	// informações do ponto I
    printf("- Energia cinética: %.3f J;\n", eih);
    printf("- Energia potencial gravitacional: %.3f J;\n", epi);
    printf("- Velocidade: %.2f m/s.\n", 0.0);	// velocidade em I é nula

    printf("\nSUA PONTUAÇÃO É: %.2f\n", pont);	// exibe pontuação final
    printf("FIM DE JOGO\n");

    return 0;
}