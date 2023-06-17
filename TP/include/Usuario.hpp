#ifndef USUARIO_H
#define USUARIO_H

#include "CaixaEntrada.hpp"

#include <iostream>

using namespace std;

class Usuario{
    private:
        int ID;
        CaixaEntrada inbox;
        Usuario *next = nullptr;

    friend class ListaUsuario;

    public:
        ~Usuario(){ }
        Usuario(int _id = 0);
};

#endif