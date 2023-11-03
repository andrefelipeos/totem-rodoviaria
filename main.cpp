#include "lista_encadeada.h"

#include <iostream>
#include <string>

using namespace std;

const char *SENHA_PARA_MANUTENCAO = "senhafraca";

void OpcoesDeManutencao();

ListaEncadeada linhas_de_onibus;

int main()
{

    cout << "O que você deseja fazer?" << endl;
    cout << "  1. Procurar linha de ônibus" << endl;
    cout << "  2. Manutenção do programa" << endl;

    int escolha;
    cin >> escolha;
    switch (escolha)
    {
    case 1:
        break;
    case 2:
        OpcoesDeManutencao();
        break;
    default:
        break;
    }

    linhas_de_onibus.ImprimeDadosFormatados();

    return 0;
}

void OpcoesDeManutencao()
{
    cout << "O que você deseja fazer?" << endl;
    cout << "  1. Adicionar uma linha de ônibus" << endl;
    cout << "  2. Alterar uma linha de ônibus" << endl;
    cout << "  3. Remover uma linha de ônibus" << endl;
    cout << "  4. Adicionar uma parada em uma linha" << endl;
    cout << "  5. Alterar uma parada em uma linha" << endl;
    cout << "  6. Remover uma parada em uma linha" << endl;

    int escolha;
    cin >> escolha;
    switch (escolha)
    {
    case 1:
        /* adicionar linha */
        int numero;
        //string companhia;
        cin >> numero;
        //cin >> companhia;
        linhas_de_onibus.InsereLinhaNoInicio(numero, "companhia");
        break;
    case 2:
        /* alterar linha */
        break;
    case 3:
        /* remover linha */
        break;
    default:
        break;
    }
}
