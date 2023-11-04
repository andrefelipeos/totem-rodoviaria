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

/*
Incluir uma parada numa linha. Neste ponto o usuário deve dizer qual o número da
linha onde quer incluir uma parada e receberá na tela uma lista numerada de todas as
paradas existentes nesta lista. Em seguida ele digita o número da parada após a qual
ele quer inserir uma parada e inserirá a parada.
*/
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
    // SE A LISTAR ESTIVER VAZIA, ADICIONAR PRIMEIRO NÓ
    // SENÃO (SE A LISTA NÃO ESTIVER VAZIA), ADICIONAR APÓS UM ÍNDICE/PARADA
    cout << "Número da linha -> " << linha->numero_da_linha << endl;
    cout << "Nome da companhia -> " << linha->nome_da_companhia << endl;
    if (linha->paradas->EstaVazia())
    {
        cout << "A lista de paradas está vazia. Adicionando primeira parada." << endl;
        string nome_da_parada;
        string horario_de_chegada;
        string horario_de_partida;
        cout << "Nome da nova parada: " << endl;
        getline(cin >> ws, nome_da_parada);
        cout << "Horário de chegada: " << endl;
        getline(cin >> ws, horario_de_chegada);
        cout << "Horário de partida: " << endl;
        getline(cin >> ws, horario_de_partida);
        linha->paradas->AdicionaPrimeiraParada(nome_da_parada, horario_de_chegada, horario_de_partida);
    }
    else
    {
        linha->paradas->ImprimeParadasNumeradas();
        cout << "Após qual parada você deseja adicionar a nova parada? " << endl;
        unsigned indice_anterior;
        cin >> indice_anterior;
        if (indice_anterior > linha->paradas->RecuperaTamanho())
        {
            cout << "Existem apenas " << linha->paradas->RecuperaTamanho() << "." << endl;
            return;
        }
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
