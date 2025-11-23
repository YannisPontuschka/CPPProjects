#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<char>> tabuleiro = {{'1', '2', '3'},
                                  {'4', '5', '6'},
                                  {'7', '8', '9'}};
char jogador_atual = 'X';
bool fim_de_jogo = false;
int jogadas = 0;

void desenha_tabuleiro()
{
    cout << "\n--- Jogo da Velha ---\n";
    cout << "Jogador 1 (X) - Jogador 2 (O)\n\n";

    cout << "     |     |     \n";
    cout << "  " << tabuleiro[0][0] << "  |  " << tabuleiro[0][1] << "  |  " << tabuleiro[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << tabuleiro[1][0] << "  |  " << tabuleiro[1][1] << "  |  " << tabuleiro[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << tabuleiro[2][0] << "  |  " << tabuleiro[2][1] << "  |  " << tabuleiro[2][2] << "  \n";
    cout << "     |     |     \n\n";
}

void faz_jogada()
{
    int escolha;
    cout << "Jogador " << jogador_atual << ", digite um número (1-9): ";
    cin >> escolha;

    int linha = (escolha - 1) / 3;
    int coluna = (escolha - 1) % 3;

    if (escolha >= 1 && escolha <= 9 && tabuleiro[linha][coluna] != 'X' && tabuleiro[linha][coluna] != 'O')
    {
        tabuleiro[linha][coluna] = jogador_atual;
        jogadas++;
    }
    else
    {
        cout << "Jogada inválida. Tente novamente.\n";
        // O `return` interrompe a função para que `checa_vitoria` e `troca_jogador` não sejam chamadas.
        return;
    }
}

bool checa_vitoria()
{
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return true;
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return true;
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return true;
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return true;

    return false;
}

void troca_jogador()
{
    if (jogador_atual == 'X')
    {
        jogador_atual = 'O';
    }
    else
    {
        jogador_atual = 'X';
    }
}

int main()
{
    while (!fim_de_jogo)
    {
        desenha_tabuleiro();
        faz_jogada();

        if (checa_vitoria())
        {
            desenha_tabuleiro();
            cout << "JOGADOR " << jogador_atual << " VENCEU! Parabéns!\n";
            fim_de_jogo = true;
            break;
        }

        if (jogadas == 9)
        {
            desenha_tabuleiro();
            cout << "DEU VELHA! O jogo empatou.\n";
            fim_de_jogo = true;
            break;
        }

        troca_jogador();
    }

    return 0;
}