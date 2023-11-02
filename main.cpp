#include "lista_encadeada.h"

#include <iostream>
#include <string>

using namespace std;

const char* SENHA_PARA_MANUTENCAO = "senhafraca";

void OpcoesDeManutencao();

int main()
{
    ListaEncadeada linhas_de_onibus;

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
}

void OpcoesDeManutencao()
{
    // incluir, alterar e eliminar linhas e paradas
}
