#ifndef NO_ENCADEAVEL_H
#define NO_ENCADEAVEL_H

#include <iostream>
#include <string>

/*
    Cada elemento desta lista possui dados sobre nº da linha e a companhia e um
    ponterio para uma lista com todas as paradas.
*/

struct NoEncadeavel
{
    unsigned numero_da_linha;
    string nome_da_companhia;
    NoEncadeavel * proximo_no;

    NoEncadeavel(unsigned numero_da_linha, string nome_da_companhia, NoEncadeavel *proximo_no = nullptr)
    {
        this->numero_da_linha = numero_da_linha;
        this->numero_da_linha = numero_da_linha;
        this->proximo_no = proximo_no;
    }

    ~NoEncadeavel()
    {
        std::cout << "Excluindo a linha " << this->numero_da_linha << " - " << this->nome_da_companhia << "\n";
    }
};

#endif
