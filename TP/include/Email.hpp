#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include "memlog.h"

using namespace std;

class Email{
    private:
        string mensagem;
        int prioridade;
        Email *next = nullptr;

    friend class CaixaEntrada;
    friend class ListaUsuario;
    friend class Usuario;

    public:
        ~Email(){ }
        Email(string _msg="", int _prioridade=0);
};

#endif