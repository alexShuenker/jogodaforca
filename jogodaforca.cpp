#include <iostream>
#include <cstdlib>
#include <random>
#include <cstring>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(0));

    // Vetores e sorteio da palavra secreta.
    string palavras[] = {"espanha", "cachorro", "pizza", "piscina", "onibus", "rato", "dentadura", "gato", "Girafa", "continente", "faca", "gorro", "risco"};
    string palavra = palavras[rand() % 13], secreta[30], letra;
    
    // Variáveis e função lenght para pegar o tamanho da palavra.
    int tamanhoPalavra = palavra.length(), chances = 15, acertos = 0;
    bool acerto = false;

    // Início do jogo.
    cout << "/****************/";
    cout << "/ Jogo de Forca */";
    cout << "/****************/" << endl;

    // Preenche o vetor "PalavraEscolhida" com "_".
    for (int i = 0; i < tamanhoPalavra; i++)
    {
        secreta[i] = "_";
    }
    //Inicia o loop do jogo.
    while ((chances > 0) && (acertos < tamanhoPalavra))
    {
        cout << "Chances restantes : " << chances << endl;

        for (int i = 0; i < tamanhoPalavra; i++)
        {
            cout << secreta[i] << " ";
        }

        cout << "\n\nDigite uma Letra: ";
        cin >> letra;

        acerto = false;  // Resetar a variável acerto para cada tentativa.

        for (int i = 0; i < tamanhoPalavra; i++)
        {
            if (palavra[i] == letra[0]) //Confere se a letra pertence a palavra e incrementa o acerto.
            {
                acerto = true;
                secreta[i] = letra[0];
                acertos++;
            }
        }

        if (!acerto) //Diminui o número de chances.
        {
            chances--;
        }
    }

    if (acertos == tamanhoPalavra) // Verifica se o jogador ganhou ou perdeu.
    {
        cout << "Voce venceu, parabens :)" << endl;
    }
    else
    {
        cout << "Nao foi dessa vez :/" << endl;
    }

    return 0;
}
