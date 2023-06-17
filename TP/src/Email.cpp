#include "Email.hpp"

Email::Email(string _msg, int _prioridade){
    this->mensagem = _msg;
    this->prioridade = _prioridade;
    this->next = nullptr;
    ESCREVEMEMLOG((long int)&(this->mensagem), sizeof(string), 0);
}