#include "lista_encadeada.h"

#include <iostream>
#include <string>

using namespace std;

const char *SENHA_PARA_MANUTENCAO = "senhafraca";

void AdicionarParada();
void MostrarTodasAsLinhas();
void OpcoesDeManutencao();
void RealizarManutencao();
void ProcurarLinhaDeOnibus();
void RemoverLinha();

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

void MostrarTodasAsLinhas()
{
    linhas_de_onibus.ImprimeDadosFormatados();
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
    cout << "  2. Mostrar todas as linhas de ônibus" << endl;
    cout << "  3. Remover uma linha de ônibus" << endl;
    cout << "  4. Adicionar uma parada em uma linha" << endl;
    cout << "  5. Alterar uma parada em uma linha" << endl;
    cout << "  6. Remover uma parada em uma linha" << endl;
}

bool AutenticaUsuario()
{
    string senha_do_usuario;
    cout << "Senha para manutenção: ";
    getline(cin >> ws, senha_do_usuario);
    if (senha_do_usuario == SENHA_PARA_MANUTENCAO)
    {
        return true;
    }
    return false;
}

void RealizarManutencao()
{
    bool usuario_autenticado = AutenticaUsuario();
    if (!usuario_autenticado)
    {
        return;
    }

    int escolha = -1;
    do
    {
        OpcoesDeManutencao();
        cin >> escolha;
        switch (escolha)
        {
        case 1:
        {
            unsigned numero;
            string companhia;
            cout << "Número da linha: ";
            cin >> numero;
            cout << "Nome da companhia: ";
            getline(cin >> ws, companhia);
            linhas_de_onibus.AdicionaNovaLinhaOrdenadamente(numero, companhia);
            break;
        }
        case 2:
            MostrarTodasAsLinhas();
            break;
        case 3:
            RemoverLinha();
            break;
        case 4:
            AdicionarParada();
            break;
        default:
            break;
        }
    } while (escolha != 0);
}

void AdicionarParada()
{
    cout << "Número da linha em que a parada será inserida: ";
    unsigned numero_da_linha;
    cin >> numero_da_linha;
    NoEncadeavel *linha = linhas_de_onibus.BuscaLinhaPeloNumero(numero_da_linha);
    if (linha == nullptr)
    {
        cout << "Indique uma linha cadastrada." << endl;
        return;
    }
    if (linha->paradas->EstaVazia())
    {
        cout << "A lista de paradas está vazia. Adicionando primeira parada." << endl;
        string nome_da_parada;
        string horario_de_chegada;
        string horario_de_partida;
        cout << "Nome da nova parada: ";
        getline(cin >> ws, nome_da_parada);
        cout << "Horário de chegada: ";
        getline(cin >> ws, horario_de_chegada);
        cout << "Horário de partida: ";
        getline(cin >> ws, horario_de_partida);
        linha->paradas->AdicionaPrimeiraParada(nome_da_parada, horario_de_chegada, horario_de_partida);
    }
    else
    {
        linha->paradas->ImprimeParadasNumeradas();
        cout << "Após qual parada você deseja adicionar a nova parada? ";
        unsigned indice_anterior;
        cin >> indice_anterior;
        if (indice_anterior > linha->paradas->RecuperaTamanho() || indice_anterior < 1)
        {
            cout << "Índice inválido. Escolha uma parada entre " << linha->paradas->RecuperaTamanho() << " parada(s) existente(s)." << endl;
            return;
        }
        string nome_da_parada;
        string horario_de_chegada;
        string horario_de_partida;
        cout << "Nome da nova parada: ";
        getline(cin >> ws, nome_da_parada);
        cout << "Horário de chegada: ";
        getline(cin >> ws, horario_de_chegada);
        cout << "Horário de partida: ";
        getline(cin >> ws, horario_de_partida);
        linha->paradas->AdicionaParadaAposIndice(indice_anterior, nome_da_parada, horario_de_chegada, horario_de_partida);
    }
}

void RemoverLinha()
{
    if (linhas_de_onibus.EstaVazia())
    {
        cout << "A lista está vazia. Não há nós para remover." << endl;
        return;
    }
    unsigned numero_da_linha;
    cout << "Número da linha para ser removida: ";
    cin >> numero_da_linha;
    linhas_de_onibus.RemoveLinhaPeloNumero(numero_da_linha);
}
