#include "../include/Usuario.hpp"

// Construtor de Usuário
Usuario::Usuario(int _id){
    this->ID = _id;
    this->next = nullptr;
}