# Jogo do Carrinho

## Descrição

O "Jogo do Carrinho" é uma simulação interativa em C, onde o jogador manipula a massa, a gravidade e a força para guiar um carrinho por uma "montanha-russa" virtual. O objetivo é calcular corretamente as propriedades físicas, como massa e gravidade, em pontos específicos para que o carrinho consiga passar por diferentes alturas ao longo do percurso. Em cada etapa, o jogo fornece feedback sobre as escolhas, indicando o valor correto em caso de erro.

## Componentes e Tecnologias

- **Linguagem de Programação**: C
- **Compilador**: GCC
- **Conceitos Físicos**: Conservação de Energia e Colisões Elásticas
- **Mecânicas do Jogo**: Ajuste de massa e gravidade em pontos específicos do trajeto para garantir o movimento do carrinho.

## Estrutura do Código

O código é dividido em funções que realizam os cálculos de energia cinética e potencial, e verifica os valores de massa, gravidade e força escolhidos pelo jogador. Ele utiliza um loop para permitir múltiplas jogadas, onde o jogador precisa ajustar os parâmetros físicos para guiar o carrinho.

## Como Jogar

1. **Clone o repositório** para sua máquina local:
   ```bash
   git clone https://github.com/nicolassm145/rollercoaster.git
   cd rollercoaster
   ```

2. **Compile o código-fonte**:
   ```bash
   gcc main.c -o main -lm
   ```

3. **Execute o jogo**:
   ```bash
   ./main
   ```

4. **Instruções do Jogo**:
   - Escolha valores de massa, gravidade e força em pontos específicos para guiar o carrinho pela montanha-russa.
   - O objetivo é calcular corretamente as variáveis para que o carrinho alcance cada ponto de altura no percurso.
   - Ao fazer escolhas erradas, o jogo fornecerá o valor correto e permitirá uma nova tentativa ou encerramento.

## Funcionalidades

- **Alteração da Massa**: Permite ajustar a massa do carrinho para diferentes trechos.
- **Ajuste da Gravidade**: O jogador define a gravidade aplicada em determinados trechos para controlar a energia do carrinho.
- **Cálculo das Energias**: O jogo exibe as energias cinética e potencial em diferentes pontos do trajeto.
- **Feedback ao Jogador**: O jogo informa sobre a precisão das escolhas e sugere o valor correto em caso de erro.

## Créditos
Este projeto foi desenvolvido por:

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/nicolassm145">
        <img src="https://avatars.githubusercontent.com/u/131420329?v=4" alt="Nícolas de Souza Moreira" style="width: 150px"><br>
        <p><strong>Nícolas de Souza Moreira</strong></p>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/flp-gregorio">
        <img src="https://avatars.githubusercontent.com/u/113314823?v=4" alt="Felipe Alves Gregorio" style="width: 150px"><br>
        <p><strong>Felipe Alves Gregorio</strong></p>
      </a>
    </td>
  </tr>
</table>

## Considerações Finais

Este jogo é uma oportunidade para aplicar conceitos de física em uma simulação prática e interativa. Sinta-se à vontade para contribuir com melhorias e explorar diferentes configurações para o trajeto do carrinho.

--- 
