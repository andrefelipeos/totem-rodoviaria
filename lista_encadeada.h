#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "no_encadeavel.h"

#include <iostream>
#include <string>

using namespace std;

/*
    Uma lista simplesmente encadeada de todas as linhas de ônibus, organizada
    por número da linha de ônibus.
*/

class ListaEncadeada
{
private:
    NoEncadeavel *primeiro_no_ = nullptr;
    NoEncadeavel *ultimo_no_ = nullptr;
    unsigned tamanho_ = 0;

public:
    ListaEncadeada() = default;

    void AdicionaNovaLinhaOrdenadamente(unsigned numero, string companhia)
    {
        if (this->EstaVazia())
        {
            this->InsereLinhaNoInicio(numero, companhia);
            this->ultimo_no_ = this->primeiro_no_;
        }
        else
        {
            if (numero < this->primeiro_no_->numero_da_linha)
            {
                this->InsereLinhaNoInicio(numero, companhia);
            }
            else if (numero > this->ultimo_no_->numero_da_linha)
            {
                this->InsereLinhaNoFinal(numero, companhia);
            }
            else
            {
                // Tem que iterar na lista para inserir no local correto!
                NoEncadeavel *no_iterador = this->primeiro_no_;
                while (numero < no_iterador->numero_da_linha)
                {
                    no_iterador = no_iterador->proximo_no;
                }
                if (numero == no_iterador->numero_da_linha)
                {
                    cout << "Número da linha inválido: os números das linhas de ônibus devem ser únicos em todo o país." << endl;
                    return;
                }
                NoEncadeavel *novo_no = new NoEncadeavel(numero, companhia, no_iterador->proximo_no);
                no_iterador->proximo_no = novo_no;
                this->tamanho_++;
            }
        }
    }

    void InsereLinhaNoFinal(unsigned numero, string companhia)
    {
        NoEncadeavel *novo_no_final = new NoEncadeavel(numero, companhia);
        this->ultimo_no_->proximo_no = novo_no_final;
        this->ultimo_no_ = novo_no_final;
        this->tamanho_++;
    }

    void InsereLinhaNoInicio(unsigned numero, string companhia)
    {
        NoEncadeavel *novo_no_inicial = new NoEncadeavel(numero, companhia);
        novo_no_inicial->proximo_no = primeiro_no_;
        this->primeiro_no_ = novo_no_inicial;
        this->tamanho_++;
    }

    void ImprimeDadosFormatados() const
    {
        NoEncadeavel *auxiliar = primeiro_no_;
        while (auxiliar != nullptr)
        {
            std::cout << "-----\n";
            std::cout << "Linha: " << auxiliar->numero_da_linha << "\n";
            std::cout << "Companhia: " << auxiliar->nome_da_companhia << "\n";
            std::cout << '\n';
            auxiliar = auxiliar->proximo_no;
        }
    }

    void RemoveLinhaPeloNumero(unsigned numero_da_linha_a_ser_removida)
    {
        if (this->EstaVazia())
        {
            cout << "A lista está vazia. Não há nós para remover.";
        }
        else
        {
            if (this->tamanho_ == 1)
            {
                delete this->primeiro_no_;
                this->primeiro_no_ = nullptr;
                this->ultimo_no_ = nullptr;
            }
            else if (this->primeiro_no_->numero_da_linha == numero_da_linha_a_ser_removida)
            {
                this->RemovePrimeiraLinha();
            }
            else if (this->ultimo_no_->numero_da_linha == numero_da_linha_a_ser_removida)
            {
                //this.RemoveUltimaLinha();
            }
            else
            {
                // remover um nó intermediário: precisa iterar
                NoEncadeavel *no_iterador = this->primeiro_no_;
                while (no_iterador->proximo_no != nullptr && numero_da_linha_a_ser_removida != no_iterador->proximo_no->numero_da_linha)
                {
                    no_iterador = no_iterador->proximo_no;
                }
                if (no_iterador == nullptr)
                {
                    // Não há uma linha com o número dado.
                    cout << "A linha " << numero_da_linha_a_ser_removida << " não existe. Nenhuma linha foi removida." << endl;
                }
                else
                {
                    // A próxima linha deve ser removida.
                    NoEncadeavel *linha_a_ser_removida = no_iterador->proximo_no;
                    no_iterador->proximo_no = linha_a_ser_removida->proximo_no;
                    delete linha_a_ser_removida;
                }
            }
            this->tamanho_--;
        }
    }

    void RemovePrimeiraLinha()
    {
        if (this->tamanho_ > 0)
        {
            NoEncadeavel *no_para_remover = this->primeiro_no_;
            this->primeiro_no_ = primeiro_no_->proximo_no;
            delete no_para_remover;
        }
    }

    void EsvaziarLista()
    {
        while (tamanho_ > 0)
        {
            NoEncadeavel *auxiliar = primeiro_no_;
            primeiro_no_ = primeiro_no_->proximo_no;
            delete auxiliar;
            tamanho_--;
        }
    }

    bool EstaVazia() const
    {
        return tamanho_ == 0;
    }

    unsigned RecuperaTamanho() const
    {
        return tamanho_;
    }

    ~ListaEncadeada()
    {
        EsvaziarLista();
        delete primeiro_no_;
    }
};

#endif
