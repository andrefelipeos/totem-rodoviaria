#ifndef NO_DUPLAMENTE_ENCADEAVEL_H
#define NO_DUPLAMENTE_ENCADEAVEL_H

#include <iostream>
#include <string>

using namespace std;

/*
    Neste elemento estão informações sobre o nome da parada, o horário de
    chegada do ônibus na rodoviária e o horário de saída do ônibus da rodoviária.
*/

struct NoDuplamenteEncadeavel
{
    string nome_da_parada;
    string horario_de_chegada;
    string horario_de_partida;
    NoDuplamenteEncadeavel *no_anterior;
    NoDuplamenteEncadeavel *proximo_no;

    NoDuplamenteEncadeavel(string nome_da_parada, string chegada, string partida)
    {
        this->nome_da_parada = nome_da_parada;
        this->horario_de_chegada = chegada;
        this->horario_de_partida = partida;
    }

    ~NoDuplamenteEncadeavel()
    {
        std::cout << "Excluindo a parada " << this->nome_da_parada << "\n";
    }
};

#endif
