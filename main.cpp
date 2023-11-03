#include "lista_encadeada.h"

#include <iostream>
#include <string>

using namespace std;

const char *SENHA_PARA_MANUTENCAO = "senhafraca";

void OpcoesDeManutencao();
void RealizarManutencao();
void ProcurarLinhaDeOnibus();

ListaEncadeada linhas_de_onibus;

int main()
{
    int escolha = -1;
    do
    {
        cout << "O que você deseja fazer?" << endl;
        cout << "  0. Encerrar o programa e sair" << endl;
        cout << "  1. Procurar uma linha de ônibus" << endl;
        cout << "  2. Realizar manutenção do programa" << endl;

        cin >> escolha;
        switch (escolha)
        {
        case 1:
            ProcurarLinhaDeOnibus();
            break;
        case 2:
            RealizarManutencao();
            break;
        default:
            break;
        }
    } while (escolha != 0);

    linhas_de_onibus.ImprimeDadosFormatados();

    return 0;
}

void ProcurarLinhaDeOnibus()
{
    cout << "Essa função ainda não foi implementada..." << endl;
}

void OpcoesDeManutencao()
{
    cout << "O que você deseja fazer?" << endl;
    cout << "  0. Encerrar manutenção do programa" << endl;
    cout << "  1. Adicionar uma linha de ônibus" << endl;
    cout << "  2. Alterar uma linha de ônibus" << endl;
    cout << "  3. Remover uma linha de ônibus" << endl;
    cout << "  4. Adicionar uma parada em uma linha" << endl;
    cout << "  5. Alterar uma parada em uma linha" << endl;
    cout << "  6. Remover uma parada em uma linha" << endl;
}

void RealizarManutencao()
{
    int escolha = -1;
    do
    {
        OpcoesDeManutencao();
        cin >> escolha;
        switch (escolha)
        {
        case 1:
        {
            int numero;
            string companhia;
            cout << "Número da linha: ";
            cin >> numero;
            cout << "Nome da companhia: ";
            getline(cin >> ws, companhia);
            linhas_de_onibus.AdicionaNovaLinhaOrdenadamente(numero, companhia);
            break;
        }
        case 2:
            /* alterar linha */
            break;
        case 3:
            /* remover linha */
            break;
        default:
            break;
        }
    } while (escolha != 0);
}
