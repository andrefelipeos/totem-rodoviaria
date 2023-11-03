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

    void ImprimeDadosFormatados()
    {
        NoDuplamenteEncadeavel *no_iterador = this->primeiro_no_;
        while (no_iterador != nullptr)
        {
            cout << "-----\n";
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

    ~ListaEncadeada()
    {
        EsvaziarLista();
    }
};

#endif
