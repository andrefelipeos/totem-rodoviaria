#ifndef LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H
#define LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H

#include "no_duplamente_encadeavel.h"

#include <iostream>
#include <string>

using namespace std;

/*
    Uma lista duplamente encadeada circular (...) onde cada elemento dessa
    lista possui dados referentes a uma parada do ônibus.
*/

class ListaDuplamenteEncadeadaCircular
{
private:
    NoDuplamenteEncadeavel *no_sentinela_ = nullptr;
    unsigned tamanho_ = 0;

public:
    ListaDuplamenteEncadeadaCircular() = default;

    /*
    Incluir uma parada numa linha. (...) o usuário (...) digita o número da
    parada após a qual ele quer inserir uma parada (...).
    */
    void AdicionaParadaAposIndice(unsigned indice_anterior, string nome_da_parada, string horario_chegada, string horario_de_partida)
    {
        if (indice_anterior > this->tamanho_)
        {
            cout << "Índice de parada fora do intervalo de paradas." << endl;
            return;
        }

        NoDuplamenteEncadeavel *no_iterador = this->no_sentinela_;
        unsigned counter = 1;
        while (counter < indice_anterior)
        {
            no_iterador = no_iterador->proximo_no;
            counter++;
        }

        NoDuplamenteEncadeavel *nova_parada = new NoDuplamenteEncadeavel(nome_da_parada, horario_de_partida, horario_chegada);
        nova_parada->no_anterior = no_iterador;
        nova_parada->proximo_no = no_iterador->proximo_no;
        no_iterador->proximo_no->no_anterior = nova_parada;
        no_iterador->proximo_no = nova_parada;
    }

    void AdicionaPrimeiraParada(string nome, string chegada, string partida)
    {
        NoDuplamenteEncadeavel *primeira_parada = new NoDuplamenteEncadeavel(nome, partida, chegada);
        primeira_parada->no_anterior = primeira_parada;
        primeira_parada->proximo_no = primeira_parada;
        this->no_sentinela_ = primeira_parada;
        this->tamanho_++;
    }

    void ImprimeParadasNumeradas() const
    {
        NoDuplamenteEncadeavel *no_iterador = this->no_sentinela_;
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
            NoDuplamenteEncadeavel *auxiliar = no_sentinela_;
            no_sentinela_ = no_sentinela_->proximo_no;
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
