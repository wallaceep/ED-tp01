#ifndef LISTAUSUARIO_H
#define LISTAUSUARIO_H

#include "Usuario.hpp"
#include "memlog.h"
#include "msgassert.h"

class ListaUsuario{
    private:
        Usuario *first = nullptr;
        Usuario *last = nullptr;
    
    public:
        ~ListaUsuario();
        Usuario *retornaUser(int _id);
        void cadastrarUsuario(int _id);
        void removerUsuario(int _id);
        void limpa();
        bool verificarExistencia(int _id);
        void entregarMsg(int _id, int _pri, string _msg);
        void consultarInbox(int _id);
};

#endif