#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "forward_list_node.h"

#include <iostream>
#include <string>

/*
    Uma lista simplesmente encadeada de todas as linhas de ônibus, organizada
    por número da linha de ônibus.
*/

class ListaEncadeada
{
private:
    NoEncadeavel *primeiro_no_;
    NoEncadeavel *ultimo_no_;
    unsigned tamanho_;

public:
    ListaEncadeada() = default;

    void InsereLinhaNoFinal(unsigned numero, string companhia)
    {
        NoEncadeavel novo_no_final = NoEncadeavel(numero, companhia);
        this->ultimo_no_ = novo_no_final;
        this->tamanho_++;
    }

    void InsereLinhaNoInicio(unsigned numero, string companhia)
    {
        NoEncadeavel novo_no_inicial = NoEncadeavel(numero, companhia);
        novo_no_inicial.proximo_no = primeiro_no_;
        this->primeiro_no_ = novo_no_inicial;
        this->tamanho_++;
    }

    void ImprimeDadosFormatados() const
    {
        NoEncadeavel *auxiliar = sentinela_;
        Node<Type> *temp = m_head;
        while (auxiliar != nullptr)
        {
            std::cout << "-----\n";
            std::cout << "Linha: " << auxiliar->numero_da_linha << "\n";
            std::cout << "Linha: " << auxiliar->nome_da_companhia << "\n";
            std::cout << '\n';
            auxiliar = auxiliar->proximo_no;
        }
    }

    void RemovePrimeiraLinha()
    {
        if (this->tamanho_ > 0)
        {
            NoEncadeavel no_para_remover = this->primeiro_no_;
            this->primeiro_no_ = primeiro_no_->proximo_no;
            delete no_para_remover;
        }
    }

    void EsvaziarLista()
    {
        while (m_head->next != m_head)
        {
            Node<Type> *aux = m_head->next;
            m_head->next = aux->next;
            aux->next->prev = aux->prev;
            delete aux;
            m_size--;
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
