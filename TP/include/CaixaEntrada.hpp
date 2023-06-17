#ifndef CAIXAENTRADA_H
#define CAIXAENTRADA_H

#include <iostream>

#include "Email.hpp"
#include "memlog.h"
#include "msgassert.h"
#include "memlog.h"

class CaixaEntrada{       
    private:
        Email *head = nullptr;
        CaixaEntrada *next = nullptr;
        int size = -1;

    friend class ListaUsuario;
    public:
        ~CaixaEntrada();
        CaixaEntrada();
        void limpa();
        void armazenarMensagens(Email *_email);
        void lerEmail();
        bool verificarVazio();
};

#endif