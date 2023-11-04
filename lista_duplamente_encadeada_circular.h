#ifndef LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H
#define LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H

#include "no_duplamente_encadeavel.h"

#include <iostream>
#include <string>

using namespace std;

/*
    Uma lista duplamente encadeada circular, para cada linha de ônibus, onde
    cada elemento dessa lista possui dados referentes a uma parada do ônibus.
*/

class ListaDuplamenteEncadeadaCircular
{
private:
    NoDuplamenteEncadeavel *primeiro_no_ = nullptr;
    NoDuplamenteEncadeavel *ultimo_no_ = nullptr;
    unsigned tamanho_ = 0;

public:
    ListaDuplamenteEncadeadaCircular() = default;

    /*
    Incluir uma parada numa linha. Neste ponto o usuário deve dizer qual o número da
linha onde quer incluir uma parada e receberá na tela uma lista numerada de todas as
paradas existentes nesta lista. Em seguida ele digita o número da parada após a qual
ele quer inserir uma parada e inserirá a parada.
    */
    void AdicionaParadaAposIndice(unsigned indice_anterior, string nome_da_parada, string horario_chegada, string horario_de_partida)
    {
        // buscar parada anterior ao ponto em que a nova parada será adicionada
        // criar e adicionar uma nova parada após a parada anteriro
        if (indice_anterior > this->tamanho_)
        {
            cout << "Índice de parada fora do intervalo de paradas." << endl;
            return;
        }

        // dá para fazer mais rápido caso o usuário escolha inserir após última parada
        // e se ele quiser inserir no início, como faz?

        NoDuplamenteEncadeavel *no_iterador = nullptr;
        if (indice_anterior == this->tamanho_)
        {
            no_iterador = this->ultimo_no_;
        }
        else
        {
            no_iterador = this->primeiro_no_;
            unsigned counter = 1;
            while (counter < indice_anterior)
            {
                no_iterador = no_iterador->proximo_no;
                counter++;
            }
        }

        NoDuplamenteEncadeavel *nova_parada = new NoDuplamenteEncadeavel(nome_da_parada, horario_de_partida, horario_chegada);
        nova_parada->no_anterior = no_iterador;
        nova_parada->proximo_no = no_iterador->proximo_no;
        no_iterador->proximo_no->no_anterior = nova_parada;
        no_iterador->proximo_no = nova_parada;
    }

    void ImprimeParadasNumeradas() const
    {
        NoDuplamenteEncadeavel *no_iterador = this->primeiro_no_;
        unsigned contador = 1;
        while (no_iterador != nullptr)
        {
            cout << "-----\n";
            cout << "Parada " << contador++;
            cout << "Nome da parada: " << no_iterador->nome_da_parada << "\n";
            cout << "Horário de chegada: " << no_iterador->horario_de_chegada << "\n";
            cout << "Horário de partida: " << no_iterador->horario_de_partida << "\n";
            cout << '\n';
            no_iterador = no_iterador->proximo_no;
        }
    }

    bool EstaVazia() const
    {
        return tamanho_ == 0;
    }

    void EsvaziarLista()
    {
        while (tamanho_ > 0)
        {
            NoDuplamenteEncadeavel *auxiliar = primeiro_no_;
            primeiro_no_ = primeiro_no_->proximo_no;
            delete auxiliar;
            tamanho_--;
        }
    }

    unsigned RecuperaTamanho() const
    {
        return this->tamanho_;
    }

    ~ListaDuplamenteEncadeadaCircular()
    {
        EsvaziarLista();
    }
};

#endif
